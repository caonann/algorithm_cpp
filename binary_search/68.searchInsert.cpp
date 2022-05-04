/*
 @filename   68.searchInsert.cpp
 @author     caonan
 @date       2022-05-04 07:05:48
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/N6YdxV
 @brief  给定一个排序的整数数组 nums 和一个整数目标值 target
，请在数组中找到 target ，并返回其下标。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
nums 为无重复元素的升序排列数组
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <list>
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
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                if (mid == 0 || nums[mid - 1] < target) {
                    return mid;
                }
            }
            if (mid == nums.size() - 1) {
                return mid + 1;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return 0;
    }
};

//简化写法，省去边界条件判断
class Solution1 : public Solution
{
   public:
    int searchInsert(vector<int>& nums, int target)
    {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int ans = size;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() { return 0; }
