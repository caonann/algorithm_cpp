/*
 @filename   28.cpp
 @author     caonan
 @date       2022-04-07 13:41:04
 @reference 剑指offer专项
 @url      https://leetcode-cn.com/problems/Qv1Da2/
 @brief
多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。
给定位于列表第一级的头节点，请扁平化列表，即将这样的多级双向链表展平成普通的双向链表，使所有结点出现在单级双链表中。
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
    Node* prev;
    Node* next;
    Node* child;
};

class Solution
{
   public:
   //时间o(n) 空间o(k) k取决于递归深度
    Node* flatten(Node* head)
    {
        getTail(head);
        return head;
    }

    Node* getTail(Node* head)
    {
        Node* tail = nullptr;
        while (head) {
            auto next = head->next;
            if (head->child) {
                auto child_end = getTail(head->child);

                child_end->next = next;
                if (next) next->prev = child_end;

                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
                tail = child_end;
            } else {
                tail = head;
            }
            head = next;
        }
        return tail;
    }
};

//直接在oj上验证了，不好构建
int main() { return 0; }
