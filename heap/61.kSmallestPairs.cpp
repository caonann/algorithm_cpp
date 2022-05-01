/*
 @filename   61.kSmallestPairs.cpp
 @author     caonan
 @date       2022-05-01 13:37:50
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/qn8gGX/
 @brief  给定两个以升序排列的整数数组 nums1 和 nums2 , 以及一个整数 k 。

定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。

请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
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
    // k^2logk的解法
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        struct node {
            node(int n1, int n2) : n1(n1), n2(n2), val(n1 + n2) {}
            int n1;
            int n2;
            int val;
        };
        auto cmp = [](const node& n1, const node& n2) { return n1.val < n2.val; };
        priority_queue<node, vector<node>, decltype(cmp)> pri_que(cmp);
        for (int i = 0; i < k && i < nums1.size(); i++) {
            for (int j = 0; j < k && j < nums2.size(); j++) {
                pri_que.emplace(node(nums1[i], nums2[j]));
                if (pri_que.size() > k) {
                    pri_que.pop();
                }
            }
        }

        vector<vector<int>> ans;
        while (!pri_que.empty()) {
            ans.emplace_back(vector<int>{pri_que.top().n1, pri_que.top().n2});
            pri_que.pop();
        }
        return ans;
    }
};

class Solution1 : public Solution
{
   public:
    // klogk解法
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        auto cmp = [&nums1, &nums2](const pair<int, int>& pair1, const pair<int, int>& pair2) {
            return nums1[pair1.first] + nums2[pair1.second] > nums1[pair2.first] + nums2[pair2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pri_que(cmp);
        //初始化初始堆
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < std::min(n1, k); ++i) {
            pri_que.emplace(make_pair(i, 0));
        }

        vector<vector<int>> ans;
        while (k-- && !pri_que.empty()) {
            auto pair = pri_que.top();
            ans.push_back({nums1[pair.first], nums2[pair.second]});
            pri_que.pop();
            if (pair.second < n2 - 1) {
                pri_que.emplace(make_pair(pair.first, pair.second + 1));
            }
        }
        return ans;
    }
};

int main() { return 0; }
