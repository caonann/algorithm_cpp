/*
 @filename   57.twoSum.cpp
 @author     caonan
 @date       2022-04-21 01:12:42
 @reference     leetcode
 @url      https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
 @brief
 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
*/
#include <assert.h>
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
    //尝试把数组看成包含任意值，用hash存 target-nums[i]
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            hash_map[target - nums[i]] = i;
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            
            if (hash_map.find(nums[i]) != hash_map.end()) {
                if (i != hash_map[nums[i]]) {
                    ans.push_back(nums[i]);
                    ans.push_back(nums[hash_map[nums[i]]]);
                    return ans;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> in{6, 18, 27, 40, 46, 57, 59, 66, 72, 91};
    auto ret = s.twoSum(in, 65);
    for (auto v : ret) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
