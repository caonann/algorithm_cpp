/*
 @filename   subarryLessEqTanK.cpp
 @author     caonan
 @date       2022-04-19 03:27:55
 @reference leetcode
 @url       https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/
 @brief  给你一个整数数组 nums 和一个整数 k ，找出 nums 中和至少为 k 的 最短非空子数组
，并返回该子数组的长度。如果不存在这样的 子数组 ，返回 -1 。
子数组 是数组中 连续 的一部分。
*/
#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include <algorithm>
#include <array>
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
    int shortestSubarray(vector<int>& nums, int k)
    {
        deque<int> monoq;
        vector<long> p(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            p[i + 1] = p[i] + nums[i];
        }

        int ans = nums.size() + 1;
        for (int y = 0; y < p.size(); y++) {
            while (!monoq.empty() && p[y] <= p[monoq.back()]) {
                monoq.pop_back();
            }
            while (!monoq.empty() && p[y] >= p[monoq.front()] + k) {
                ans = min(ans, y - monoq.front());
                monoq.pop_front();
            }
            monoq.push_back(y);
        }
        return ans < nums.size() + 1 ? ans : -1;
    }
};

int main()
{
    Solution s;
    vector<int> in{2, -1, 2};
    cout << s.shortestSubarray(in, 3) << endl;
    return 0;
}
