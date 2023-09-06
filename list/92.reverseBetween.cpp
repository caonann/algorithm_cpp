/*
 @filename   92.reverseBetween.cpp
 @author     caonan
 @date       2022-04-28 07:08:20
 @reference   leetcode
 @url      https://leetcode-cn.com/problems/reverse-linked-list-ii/
 @brief  给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right
 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
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

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) {
      return head;
    }
    ListNode dummy(-1000, head);
    ListNode *it = &dummy;
    int step = right - left;
    auto *pre = it;
    while (left--) {
      pre = it;
      it = it->next;
    }
    auto *head_cut = it;
    while (step--) {
      it = it->next;
    }
    auto *tail = it->next;
    it->next = nullptr;
    auto *new_head = reverse(head_cut);
    pre->next = new_head;
    while (new_head->next != nullptr) {
      new_head = new_head->next;
    }
    new_head->next = tail;
    return dummy.next;
  }

 private:
  ListNode *reverse(ListNode *head) {
    ListNode *pre = nullptr;
    while (head != nullptr) {
      auto *next = head->next;
      head->next = pre;
      pre = head;
      head = next;
    }
    return pre;
  }
};

//一次遍历，相比第一种方法，好处是只遍历一次
class Solution2 {
 public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    auto *dummy = new ListNode(-1);
    dummy->next = head;
    auto *pre = dummy;
    for (int i = 0; i < left - 1; ++i) {
      pre = pre->next;
    }

    auto *cur = pre->next;
    ListNode *next;
    for (int i = 0; i < right - left; i++) {
      next = cur->next;
      cur->next = next->next;
      next->next = pre->next;
      pre->next = next;
    }
    return dummy->next;
  }
};

int main() {
  ListNode *head = new ListNode(5);
  Solution s;
  s.reverseBetween(head, 1, 1);
  return 0;
}
