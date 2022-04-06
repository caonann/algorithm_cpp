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
#include <unordered_set>
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
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> hash_set;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *it = &dummy;
        while (it) {
            if (hash_set.find(it) != hash_set.end()) {
                return it;
            }
            hash_set.insert(it);
            it = it->next;
        }
        return nullptr;
    }
};

class Solution1 : public Solution
{
   public:
    //方法2.求出环的长度n，然后用快慢指针从头遍历，间隔n，那么慢指针指向的位置就是入环点
    //方法2优化，根据一系列数学推导，可知当快慢指针相交时（快是慢的两倍），必有从换的相交点和从链表头等速移动相交点即为入环点
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast) {
            if (fast->next) {
                fast = fast->next->next;
            } else {
                return nullptr;
            }
            slow = slow->next;
            if (slow == fast) {
                slow = head;
                while (1) {
                    if (slow == fast) {
                        return slow;
                    }
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
        return nullptr;
    }
};

ListNode *createCycleList(vector<int> arr, int cycle_val)
{
    ListNode dummy(-1);
    ListNode *it = &dummy;
    ListNode *cycle_val_ptr = nullptr;
    for (auto val : arr) {
        it->next = new ListNode(val);
        it = it->next;
        if (val == cycle_val) {
            cycle_val_ptr = it;
        }
    }

    assert(cycle_val_ptr);
    it->next = cycle_val_ptr;
    return dummy.next;
}

void showCycleList(ListNode *head)
{
    Solution1 s;
    ListNode *it = s.detectCycle(head);
    if (!it) {
        printf("the list does not have a cycle\n");
        return;
    }
    int node_len = 0;
    ListNode *tmp = it;
    do {
        tmp = tmp->next;
        node_len++;
    } while (tmp != it);

    assert(node_len > 4);
    bool isOdd = node_len % 2 == 1;
    node_len = isOdd ? ++node_len : node_len;

    int height = node_len / 4;
    int width = (node_len - height * 2) / 2;
    height += 2;

    int out_cycle_line_len = 10;
    int left_col_printable_idx = out_cycle_line_len;
    int right_col_printable_idx = out_cycle_line_len + width - 1;
    int top_row_printable_idx = 0;
    int bottom_row_printable_idx = height - 1;

    for (int col = 0; col < height; col++) {
        for (int cow = 0; cow < width + out_cycle_line_len; cow++) {
            if (col == bottom_row_printable_idx) {
                if (cow >= left_col_printable_idx) {
                    if (isOdd) {
                        printf(" ");
                        isOdd = false;
                    } else {
                        printf("#");
                    }
                } else {
                    printf(" ");
                }
            } else if (col == top_row_printable_idx) {
                printf("#");
            } else if (cow == left_col_printable_idx || cow == right_col_printable_idx) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    Solution s;
    ListNode *head = createCycleList(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}, 8);
    showCycleList(head);
    return 0;
}
