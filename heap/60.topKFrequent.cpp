/*
 @filename   60.topKFrequent.cpp
 @author     caonan
 @date       2022-05-01 12:57:24
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/g5c51o/
 @brief  给定一个整数数组 nums 和一个整数 k ，请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
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
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash_map;
        for (auto n : nums) {
            hash_map[n]++;
        }
        struct node {
            node(int key, int val) : key(key), val(val) {}
            int key;
            int val;
        };
        auto cmp = [](const node& left, const node& right) { return left.val > right.val; };
        priority_queue<node, vector<node>, decltype(cmp)> pri_que(cmp);
        for (auto it = hash_map.begin(); it != hash_map.end(); ++it) {
            pri_que.emplace(node(it->first, it->second));
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }

        vector<int> ans;
        while (!pri_que.empty()) {
            ans.push_back(pri_que.top().key);
            pri_que.pop();
        }
        return ans;
    }
};

int main() { return 0; }
