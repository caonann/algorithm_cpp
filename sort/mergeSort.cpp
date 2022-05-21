/*
 @filename   mergeSort.cpp
 @author     caonan
 @date       2022-05-15 16:33:00
 @reference   leetcode
 @url      https://leetcode-cn.com/problems/sort-an-array/
 @brief  实现归并排序
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

#include "../util/util.h"
using namespace std;

//考虑迭代的解法
class Solution
{
   public:
    vector<int> sortArray(vector<int>& nums) {}
};

//递归归并,这种写法比较容易理解
class Solution1 : public Solution
{
   public:
    vector<int> sortArray(vector<int>& nums)
    {
        merge(0, nums.size() - 1, nums);
        return nums;
    }

   private:
    void merge(int start, int end, vector<int>& nums)
    {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        merge(start, mid, nums);
        merge(mid + 1, end, nums);
        partation(start, end, nums);
    }
    void partation(int start, int end, vector<int>& nums)
    {
        int start1 = start;
        int end1 = start + (end - start) / 2;
        int start2 = end1 + 1;
        int end2 = end;
        vector<int> tmp_arr;
        while (start1 <= end1 && start2 <= end2) {
            if (nums[start1] < nums[start2]) {
                tmp_arr.push_back(nums[start1++]);
            } else {
                tmp_arr.push_back(nums[start2++]);
            }
        }
        while (start1 <= end1) {
            tmp_arr.push_back(nums[start1++]);
        }
        while (start2 <= end2) {
            tmp_arr.push_back(nums[start2++]);
        }

        for (int i = 0; i < tmp_arr.size(); i++) {
            nums[i + start] = tmp_arr[i];
        }
    }
};

//同solution1,但是代码要更简洁
class Solution2 : public Solution
{
   public:
    vector<int> sortArray(vector<int>& nums)
    {
        vector<int> res(nums.size(), 0);
        merge(0, nums.size() - 1, nums);
        return nums;
    }

   private:
    void merge(int start, int end, vector<int>& nums)
    {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        merge(start, mid, nums);
        merge(mid + 1, end, nums);
        vector<int> res;
        int i = start, j = mid + 1;
        while (i <= mid || j <= end) {
            if (j > end || i <= mid && nums[i] < nums[j]) {
                res.push_back(nums[i++]);
            } else {
                res.push_back(nums[j++]);
            }
        }
        for (int i = 0; i < res.size(); i++) {
            nums[start + i] = res[i];
        }
    }
};
int main()
{
    // vector<int> in{3, 2, 1, 5, 7, 6, 8, 9, 0};
    vector<int> in{1, 2, 1, 2, 1, 2, 1, 2};
    Solution2 s;
    auto ret = s.sortArray(in);
    printItemList(ret);
    return 0;
}
