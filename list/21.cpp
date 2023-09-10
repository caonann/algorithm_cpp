/*
 @filename   21.cpp
 @author     caonan
 @date       2022-04-05 00:46:51
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/SLwz0R/
 @brief    给定一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // 关键是快慢指针，倒数n+1个节点开始计数 考虑n取值 n>=0
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;
    int i = 0;
    while (i < n + 1 && (fast != nullptr)) {
      fast = fast->next;
      ++i;
    }

    if (n == 0 || i < n) {
      return head;
    }
    if (i == n) {
      return head->next;
    }

    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    slow->next = slow->next->next;
    return head;
  }

  // 使用哨兵节点，简化代码逻辑 1<=n<=链表长度，如果超出这个范围，还是要特殊判断
  ListNode* removeNthFromEnd1(ListNode* head, int n) {
    ListNode dummy = ListNode(-1, head);
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;
    while (n-- >= 0 && (fast != nullptr)) {
      fast = fast->next;
    }

    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy.next;
  }
};

ListNode* createList(vector<int> arr) {
  if (arr.empty()) {
    return nullptr;
  }
  auto* head = new ListNode(arr[0]);
  ListNode* tmp = head;
  for (int i = 1; i < arr.size(); i++) {
    tmp->next = new ListNode(arr[i]);
    tmp = tmp->next;
  }
  return head;
}

void printNodeList(ListNode* node) {
  while (node) {
    cout << node->val << " ";
    node = node->next;
  }
  cout << endl;
}
int main() {
  ListNode* head = createList(vector<int>{1, 2, 3, 4, 5, 6, 7});
  printNodeList(head);
  Solution s;
  printNodeList(s.removeNthFromEnd1(head, 7));
  return 0;
}
