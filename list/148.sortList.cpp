/*
 @filename   148.sortList.cpp
 @author     caonan
 @date       2022-04-26 12:13:46
 @reference   leetcode
 @url      https://leetcode-cn.com/problems/sort-list/
 @brief  给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
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
    //自顶向下归并
    ListNode* sortList(ListNode* head) { return sortList(head, nullptr); }

   private:
    ListNode* sortList(ListNode* head, ListNode* tail)
    {
        if (!head) return nullptr;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        auto mid = getMid(head, tail);
        auto head1 = sortList(head, mid);
        auto head2 = sortList(mid, tail);
        return merge(head1, head2);
    }
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode dummy(-1);
        ListNode* pre = &dummy;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                pre->next = head1;
                head1 = head1->next;
            } else {
                pre->next = head2;
                head2 = head2->next;
            }
            pre = pre->next;
        }
        pre->next = head1 ? head1 : head2;
        return dummy.next;
    }

    ListNode* getMid(ListNode* head, ListNode* tail)
    {
        auto fast = head, slow = head;
        while (fast != tail) {
            fast = fast->next;
            if (fast != tail) fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

class Solution1 : public Solution
{
   public:
    // todo 自底向上归并
    ListNode* sortList(ListNode* head) {}
};
int main() { return 0; }
