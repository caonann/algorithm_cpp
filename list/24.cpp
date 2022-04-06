/*
 @filename   24.cpp
 @author     caonan
 @date       2022-04-06 11:39:49
 @reference 剑指offer专项
 @url       https://leetcode-cn.com/problems/UHnkqh/
 @brief     给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。
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

class Solution
{
   public:
    //这版写的太冗长了
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p1 = head;
        if (!p1) return nullptr;
        ListNode* p2 = p1->next;
        if (!p2) return head;
        ListNode* p3 = p2->next;
        if (!p3) {
            p2->next = p1;
            p1->next = nullptr;
            return p2;
        }
        p1->next = nullptr;
        while (p3) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        return p2;
    }
};

class Solution1 : public Solution
{
   public:
    //代码简化版
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

ListNode* createList(vector<int> arr)
{
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* tmp = head;
    for (int i = 1; i < arr.size(); i++) {
        tmp->next = new ListNode(arr[i]);
        tmp = tmp->next;
    }
    return head;
}

void show_node_list(ListNode* head)
{
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    auto p = createList(vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
    Solution1 s;
    p = s.reverseList(p);
    show_node_list(p);
    return 0;
}
