/*
 @filename   21.mergeTwoLists.cpp
 @author     caonan
 @date       2022-04-26 12:40:52
 @reference    leetcode
 @url      https://leetcode-cn.com/problems/merge-two-sorted-lists/
 @brief  将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                pre->next = list1;
                list1 = list1->next;
            } else {
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }
        pre->next = list1 ? list1 : list2;
        return dummy->next;
    }
};

int main() { return 0; }
