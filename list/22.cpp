/*
 @filename   22.cpp
 @author     caonan
 @date       2022-04-05 02:52:04
 @reference   剑指offer专项
 @url      https://leetcode-cn.com/problems/c32eOV/
 @brief 给定一个链表，返回链表开始入环的第一个节点。 从链表的头节点开始沿着
 next指针进入环的第一个节点为环的入口节点。如果链表无环，则返回 null。为了表示给定链表中的环，我们使用整数pos
 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果
 pos是-1，则在该链表中没有环。注意，pos
 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
*/

#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
   public:
    //方法1.hash表
    ListNode *detectCycle(ListNode *head) {
        
    }

    //方法2.求出环的长度n，然后用快慢指针从头遍历，间隔n，那么慢指针指向的位置就是入环点
    //方法2优化，根据一系列数学推导，可知当快慢指针相交时（快是慢的两倍），必有从换的相交点和从链表头等速移动相交点即为入环点
    ListNode *detectCycle1(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        int i = 1;
        while (fast) {
            fast = fast->next;
            if (i % 2 == 0) {
                slow = slow->next;
            }
            if (slow == fast) {
            }
        }

        return nullptr;
    }
};

int main()
{
    Solution s;
    return 0;
}
