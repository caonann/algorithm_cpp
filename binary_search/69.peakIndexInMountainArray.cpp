/*
 @filename   69.peakIndexInMountainArray.cpp
 @author     caonan
 @date       2022-05-04 07:33:59
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/B1IidL
 @brief  符合下列属性的数组 arr 称为 山峰数组（山脉数组） ：

arr.length >= 3
存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给定由整数组成的山峰数组 arr ，返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... >
arr[arr.length - 1] 的下标 i ，即山峰顶部。

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
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int size = arr.size();
        if (size == 1) return 0;
        int left = 0;
        int right = size - 1;
        int ans = size;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == size - 1) {
                ans = arr[mid - 1] > arr[mid] ? mid - 1 : mid;
                break;
            }
            if (mid == 0) {
                ans = arr[mid] > arr[mid + 1] ? mid : mid + 1;
                break;
            }
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                ans = mid;
                break;
            }
            if (arr[mid] < arr[mid - 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

//最小的i，满足arr[i]>arr[i+1]即为答案
class Solution1 : Solution
{
   public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int l = 0;
        int r = arr.size() - 2;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid + 1]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
int main() { return 0; }
