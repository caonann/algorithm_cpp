/*
 @filename   82.deleteDuplicates.cpp
 @author     caonan
 @date       2022-04-27 11:40:12
 @reference   leetcode
 @url      https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 @brief  给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head) return nullptr;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* cur = &dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int same_val = cur->next->val;
                while (cur->next && cur->next->val == same_val) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};
int main() { return 0; }
