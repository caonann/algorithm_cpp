/*
 @filename   29.cpp
 @author     caonan
 @date       2022-04-08 03:34:28
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/4ueAj6/
 @brief   给定循环单调非递减列表中的一个点，写一个函数向这个列表中插入一个新元素 insertVal
，使这个列表仍然是循环升序的。 给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。
如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。
如果列表为空（给定的节点是 null），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。
*/

#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node
{
   public:
    int val;
    Node* next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next)
    {
        val = _val;
        next = _next;
    }
};

class Solution
{
   public:
    Node* insert(Node* head, int insertVal)
    {
        if (!head) {
            auto p = new Node(insertVal);
            p->next = p;
            return p;
        }
        Node dummy(-1, head);
        Node *slow = &dummy, *fast = &dummy;
        Node* max_val_ptr = head;
        auto insert_val = [](Node* p, int val) {
            auto next = p->next;
            p->next = new Node(val);
            p->next->next = next;
        };
        while (true) {
            slow = slow->next;
            fast = fast->next->next;
            max_val_ptr = slow->val >= max_val_ptr->val ? slow : max_val_ptr;
            if (slow->val == insertVal || slow->val < insertVal && insertVal < slow->next->val) {
                insert_val(slow, insertVal);
                break;
            }
            if (slow == fast) {
                insert_val(max_val_ptr, insertVal);
                break;
            }
        }
        return head;
    }
};

int main() { return 0; }
