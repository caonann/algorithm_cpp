/*
 @filename   75.relativeSortArray.cpp
 @author     caonan
 @date       2022-05-08 13:42:15
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/0H97ZC
 @brief  给定两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1
中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
*/
#include <assert.h>
#include <limits.h>
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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        int min = INT_MAX, max = INT_MIN;
        vector<int> ans;
        for (auto n : arr1) {
            min = std::min(min, n);
            max = std::max(max, n);
        }

        vector<int> counts(max - min + 1, 0);
        for (auto n : arr1) {
            counts[n - min]++;
        }
        for (auto n : arr2) {
            while (counts[n - min]-- > 0) {
                ans.push_back(n);
            }
        }
        for (int num = min; num <= max; num++) {
            while (counts[num - min]-- > 0) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2{2, 1, 4, 3, 9, 6};
    Solution s;
    auto ret = s.relativeSortArray(arr1, arr2);
    printItemList(ret);
    return 0;
}
