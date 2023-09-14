/*
 @filename   list/23.mergeKLists.cpp
 @author     caonan
 @date       2023-09-12 08:51:57
 @reference leetcode
 @url
 https://leetcode.cn/problems/merge-k-sorted-lists/solutions/219756/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/
 @brief
*/
#include <cassert>
#include <climits>
#include <cstdio>

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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// TODO: 自己写通过的 非最优解
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto* dummy = new ListNode(-1);
    auto* cur = dummy;
    if (lists.empty()) {
      return nullptr;
    }
    while (true) {
      int list_alive = 0;
      int min = 100000;
      int imin = 0;
      for (int i = 0; i < lists.size(); ++i) {
        if (lists[i] == nullptr) {
          continue;
        }
        list_alive++;
        if (lists[i]->val < min) {
          imin = i;
          min = lists[i]->val;
        }
      }

      cur->next = lists[imin];
      if (list_alive <= 1) {
        break;
      }
      cur = cur->next;
      lists[imin] = lists[imin]->next;
    }
    return dummy->next;
  }
};

int main() {
  auto* p1 = new ListNode(1, new ListNode(4, new ListNode(5)));
  auto* p2 = new ListNode(1, new ListNode(3, new ListNode(4)));
  auto* p3 = new ListNode(2, new ListNode(6));
  Solution s;
  vector<ListNode*> lists = {p1, p2, p3};
  auto* ret = s.mergeKLists(lists);
  while (ret != nullptr) {
    cout << ret->val << " ";
    ret = ret->next;
  }
  return 0;
}
