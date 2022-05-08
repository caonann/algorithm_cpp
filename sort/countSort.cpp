/*
 @filename   countSort.cpp
 @author     caonan
 @date       2022-05-08 13:43:45
 @reference    leetcode
 @url      https://leetcode-cn.com/problems/sort-an-array/
 @brief  排序，使用计数排序
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
    vector<int> sortArray(vector<int>& nums)
    {
        int max = INT_MIN;
        int min = INT_MAX;
        for (auto n : nums) {
            max = std::max(max, n);
            min = std::min(min, n);
        }
        vector<int> counts(max - min + 1, 0);
        for (auto n : nums) {
            counts[n - min]++;
        }
        int i = 0;
        for (int num = min; num <= max; num++) {
            while (counts[num - min]-- > 0) {
                nums[i++] = num;
            }
        }
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> in{3, 2, 4, 1, 6, 8, 7};
    auto ret = s.sortArray(in);
    printItemList(ret);
    return 0;
}
