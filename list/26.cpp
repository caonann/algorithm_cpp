/*
 @filename   26.cpp
 @author     caonan
 @date       2022-04-07 03:03:21
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/LGjMqU/
 @brief  给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 L0 → L1 → … → Ln-1 → Ln 
请将其重新排列后变为：
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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
    void reorderList(ListNode* head)
    {
        vector<ListNode*> list_arr;
        while (head) {
            list_arr.push_back(head);
            head = head->next;
        }
        int n = list_arr.size() - 1;
        int i = 0;
        while (true) {
            if (i == n) {
                list_arr[i]->next = nullptr;
                break;
            }
            list_arr[i]->next = list_arr[n];
            if (i + 1 >= n) {
                list_arr[n]->next = nullptr;
                break;
            }
            list_arr[n]->next = list_arr[i + 1];
            ++i;
            --n;
        }
    }
};

class Solution1 : public Solution
{
   public:
    void reorderList(ListNode* head)
    {
        ListNode *fast = head, *slow = head;
        while (fast) {
            if (fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                fast = fast->next;
            }
        }

        auto shorter = reverseList(slow->next);
        slow->next = nullptr;
        auto longer = head;
        while (longer && shorter) {
            auto tmp = shorter->next;
            shorter->next = longer->next;
            longer->next = shorter;
            longer = shorter->next;
            shorter = tmp;
        }
    }

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

void printNodeList(ListNode* node)
{
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

void uint_test(vector<int> arr)
{
    static int test_times = 0;
    cout << "----------test times " << test_times++ << "----------" << endl;
    auto p = createList(arr);
    Solution1 s;
    s.reorderList(p);
    printNodeList(p);
}
int main()
{
    uint_test(vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8});
    uint_test(vector<int>{1, 2, 3, 4, 5});
    uint_test(vector<int>{1, 2, 3});
    return 0;
}
