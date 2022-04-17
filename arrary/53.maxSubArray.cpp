/*
 @filename   53.maxSubArray.cpp
 @author     caonan
 @date       2022-04-17 07:55:13
 @reference     leetcode
 @url      https://leetcode-cn.com/problems/maximum-subarray/
 @brief  给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。
*/
#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
   public:
    //只要连续的累加和小于0,则重新开始累加,其实也是动态规划的思想
    int maxSubArray(vector<int>& nums)
    {
        assert(!nums.empty());
        int max_sum = nums[0];
        int tmp = max_sum;
        for (int i = 1; i < nums.size(); ++i) {
            if (tmp < 0)
                tmp = nums[i];
            else
                tmp += nums[i];
            max_sum = std::max(max_sum, tmp);
        }
        return max_sum;
    }
};

//动态规划思想,非递归
class Solution1 : public Solution
{
   public:
    int maxSubArray(vector<int>& nums)
    {
        int pre = 0;
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            pre = std::max(pre + nums[i], nums[i]);
            max = std::max(max, pre);
        }
        return max;
    }
};

//用递归实现动归思想
class Solution2 : public Solution
{
   public:
    int maxSubArray(vector<int>& nums)
    {
        int max = nums[0];
        int tmp = f(nums.size() - 1, nums, max);
        return max;
    }

   private:
    int f(int i, const vector<int>& nums, int& max)
    {
        if (i == 0) return nums[0];
        int sum = f(i - 1, nums, max);
        if (sum <= 0) {
            max = std::max(nums[i], max);
            return nums[i];
        }
        max = std::max(sum + nums[i], max);
        return sum + nums[i];
    }
};

//分治方法，进阶扩展到线段树
class Solution3 : public Solution
{
   public:
    int maxSubArray(vector<int>& nums)
    {
        SegmentStatus s = divide(0, nums.size() - 1, nums);
        return s.msum;
    }

   private:
    struct SegmentStatus {
        int isum, lsum, rsum, msum;
    };
    SegmentStatus divide(int start, int end, const vector<int>& nums)
    {
        SegmentStatus s;
        if (start == end) return SegmentStatus{nums[start], nums[start], nums[start], nums[start]};
        int mid = start + (end - start) / 2;
        SegmentStatus l_info = divide(start, mid, nums);
        SegmentStatus r_info = divide(mid + 1, end, nums);
        s.isum = l_info.isum + r_info.isum;
        s.lsum = std::max(l_info.lsum, l_info.isum + r_info.lsum);
        s.rsum = std::max(r_info.rsum, r_info.isum + l_info.rsum);
        s.msum = std::max(l_info.msum, r_info.msum);
        s.msum = std::max(s.msum, l_info.rsum + r_info.lsum);
        return s;
    }
};

int main()
{
    Solution3 s;
    vector<int> in{-1, 0, -2};
    int ret = s.maxSubArray(in);
    cout << ret << endl;
    return 0;
}
