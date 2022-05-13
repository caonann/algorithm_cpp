/*
 @filename   quickSort.cpp
 @author     caonan
 @date       2022-05-09 16:58:02
 @reference     leetcode
 @url      https://leetcode.cn/problems/sort-an-array/
 @brief  实现快速排序
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

class Solution
{
   public:
    vector<int> sortArray(vector<int>& nums)
    {
        quickSort(0, nums.size() - 1, nums);
        return nums;
    }

   private:
    void quickSort(int start, int end, vector<int>& nums)
    {
        if (start >= end) return;
        int pos = swap(start, end, nums);
        quickSort(start, pos - 1, nums);
        quickSort(pos + 1, end, nums);
    }

    int swap(int start, int end, vector<int>& nums)
    {
        int p1 = start - 1;
        // std::swap(nums[start], nums[end]);//这里如果选开头第一个，最坏时间复杂度接近on^2
        int random = RandomUtils::getInt(start, end);
        std::swap(nums[random], nums[end]);
        for (int p2 = start; p2 < end; p2++) {
            if (nums[p2] < nums[end]) {
                p1++;
                std::swap(nums[p1], nums[p2]);
            }
        }
        p1++;
        std::swap(nums[p1], nums[end]);
        return p1;
    }
};

int main()
{
    vector<int> in{2, 3, 1, 5, 8, 7, 4};
    Solution s;
    auto ret = s.sortArray(in);
    printItemList(ret);
    return 0;
}
