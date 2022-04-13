/*
 @filename   10.cpp
 @author     caonan
 @date       2022-03-20 14:34:11
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/QTMn0o/
 @brief    给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。
*/
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// 时间 o(n) 空间o(n)
/*
由于给出的数据范围-1000 <= nums[i] <=
1000其中是有负数的，区间和的变化并不是稳定递增的，此时之前一贯的滑动窗口的做法就不可行了
在这里我们需要借助另一个前缀和的概念
前缀和数组对应于原数组，表示从开始位置，到数组中各项当前位置的所有项的和。
这样当我们要求某个区间的和的时候，就可以用末尾的前缀和减去区间开始位置的前缀和即可。
不过此处我们并不需要直接计算出前缀和，我们需要再借助一个哈希表
在上面的内容中，我们知道了前缀和的知识，这样在遍历求前缀和的过程中，
我们知道了当前位置的前缀和，又知道了区间和k，那么我们只需要判断在当前位置之前有几个位置的前缀和为当前位置的前缀和 -
k的情况即可 所以在遍历的求前缀和的时候，只需在哈希表中统计到不同的前缀和出现了几次，本题思路计算解析完成了
*/

class Solution
{
   public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash_map;
        int sum = 0;
        int total_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hash_map.find(sum - k) != hash_map.end()) {
                total_count += hash_map[sum - k];
            }
            hash_map[sum]++;
            if (sum == k) {
                total_count++;
            }
        }
        return total_count;
    }

    //代码简化，思路同上
    int subarraySum2(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash_map{{0, 1}};
        int sum = 0;
        int total_count = 0;
        for (auto num : nums) {
            sum += num;
            total_count += hash_map.find(sum - k) != hash_map.end() ? hash_map[sum - k] : 0;
            hash_map[sum]++;
        }
        return total_count;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 1, 1};
    assert(s.subarraySum(nums, 2) == 2);
    assert(s.subarraySum2(nums, 2) == 2);
    vector<int> nums1{1, 2, 3};
    assert(s.subarraySum(nums1, 3) == 2);
    assert(s.subarraySum2(nums1, 3) == 2);
    vector<int> nums2{1};
    assert(s.subarraySum(nums2, 0) == 0);
    assert(s.subarraySum2(nums2, 0) == 0);
    vector<int> nums3{0, 0, 0, 1};
    assert(s.subarraySum(nums3, 1) == 4);
    assert(s.subarraySum2(nums3, 1) == 4);
    vector<int> nums4{1, 0, 0, 0};
    assert(s.subarraySum(nums4, 1) == 4);
    assert(s.subarraySum2(nums4, 1) == 4);
    return 0;
}
