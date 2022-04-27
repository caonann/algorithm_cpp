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
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <assert.h>
using namespace std;

class Solution
{
   public:
   //todo:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        map<int, int> map_store;
        int min = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            auto it = map_store.upper_bound(nums[i]);
            int upper = it != map_store.end() ? it->first - nums[i] : INT_MAX;
            if (it != map_store.end()) --it;
            int lower = it != map_store.end() ? nums[i] - it->first : INT_MAX;
            cout << "upper " << upper << " lower " << lower << endl;
            int less = std::min(upper, lower);
            int min = std::min(min, less);
            map_store[nums[i]];
            cout<<"min "<<min<<endl;
            if (min <= t) return true;
            if (i >= k) map_store.erase(nums[i - k]);
        }

        return false;
    }
};

bool unit_test(vector<int> arr, int k, int t)
{
    Solution s;
    vector<int> in{1, 5, 9, 1, 5, 9};
    return s.containsNearbyAlmostDuplicate(in, k, t);
}
int main()
{   
    auto ret = unit_test(vector<int>{1, 5, 9, 1, 5, 9}, 2, 3);
    assert(ret == false);
    unit_test(vector<int>{1,0,1,1},1,2);
    return 0;
}
