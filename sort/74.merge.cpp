/*
 @filename   74.merge.cpp
 @author     caonan
 @date       2022-05-07 15:04:58
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/SsGoHC
 @brief  以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
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
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        auto cmp = [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; };
        std::sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            int begin = intervals[i][0];
            int end = intervals[i][1];

            while (i < intervals.size() - 1 && end >= intervals[i + 1][0]) {
                end = std::max(end, intervals[i + 1][1]);
                ++i;
            }
            ans.emplace_back(vector<int>{begin, end});
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> in{{1, 3}, {2, 9}, {8, 13}, {4, 6}};
    auto retlist = s.merge(in);
    for (auto ret : retlist) {
        printf("[%d,%d] ", ret[0], ret[1]);
    }
    cout << endl;
    return 0;
}
