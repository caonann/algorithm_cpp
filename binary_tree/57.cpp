/*
 @filename   57.cpp
 @author     caonan
 @date       2022-04-23 17:04:36
 @reference   剑指offer专项
 @url      https://leetcode-cn.com/problems/7WqeDu/
 @brief  给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <=
t ，同时又满足 abs(i - j) <= k 。 如果存在则返回 true，不存在返回 false。
*/
#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
   public:
    // todo:整型溢出场景导致没过
    // c++的map 查询小于 target的最大值喝大于target的最小值
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        set<int> set_store;
        long min = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            auto it = set_store.lower_bound(nums[i]);
            if (it != set_store.end()) {
                min = std::min(min, labs(nums[i] - *it));
            }

            if (!set_store.empty()) {
                auto rit = set_store.rbegin();
                min = std::min(min, labs(nums[i] - *rit));
            }

            if (min <= t) return true;
            if (i >= k && nums[i] != nums[i - k]) set_store.erase(nums[i - k]);
            set_store.insert(nums[i]);
        }

        return false;
    }
};

bool uinttest(vector<int> arr, int k, int t)
{
    Solution s;
    return s.containsNearbyAlmostDuplicate(arr, k, t);
}
int main()
{
    auto ret = uinttest(vector<int>{1, 5, 9, 1, 5, 9}, 2, 3);
    assert(ret == false);
    uinttest(vector<int>{1, 0, 1, 1}, 1, 2);
    uinttest(vector<int>{1, 2, 3, 1}, 3, 0);
    uinttest(vector<int>{1, 2, 1, 1}, 1, 0);
    uinttest(vector<int>{-2147483648, 2147483647}, 1, 1);
    return 0;
}
