/*
 @filename   subarraySum.cpp
 @author     caonan
 @date       2022-04-12 15:21:15
 @reference
 @url      https://leetcode-cn.com/problems/subarray-sum-equals-k/
 @brief  给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
   public:
    //暴力方法o(n^2)
    int subarraySum(vector<int>& nums, int k)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution1 : public Solution
{
   public:
    //前缀和
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> count_map;
        int pre = 0;
        int count = 0;
        count_map[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (count_map.find(pre - k) != count_map.end()) {
                count += count_map[pre - k];
            }
            count_map[pre]++;
        }
        return count;
    }
};

void uinttest(vector<int> arr, int k, int expect)
{
    Solution s;
    int ret = s.subarraySum(arr, k);
    printf("expect %d,ret %d\n", expect, ret);
}
int main()
{
    uinttest(vector<int>{1, 1, 1}, 2, 2);
    return 0;
}
