/*
 @filename   71.randomIndexPick.cpp
 @author     caonan
 @date       2022-05-04 13:03:31
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/cuyjEf
 @brief  给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0
开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 i 的概率与 w[i] 成正比。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) =
0.75（即，75%）。

也就是说，选取下标 i 的概率为 w[i] / sum(w) 。

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
    Solution(vector<int>& w)
    {
        int total = 0;
        for (auto n : w) {
            total += n;
            total_sum_.push_back(total);
        }
    }

    int pickIndex()
    {
        int p = RandomUtils::getInt(1, total_sum_.back());
        int l = 0;
        int r = total_sum_.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (total_sum_[mid] >= p) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

   private:
    vector<int> total_sum_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main()
{
    vector<int> in{1, 3};
    Solution s(in);
    for (int i = 0; i < 5; i++) {
        cout << "ret:" << s.pickIndex() << endl;
    }

    return 0;
}
