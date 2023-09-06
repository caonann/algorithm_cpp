/*
 @filename   25.cpp
 @author     caonan
 @date       2022-04-06 15:24:33
 @reference 剑指offer专项
 @url       https://leetcode-cn.com/problems/lMSNwu/
 @brief     给定两个 非空链表
 l1和l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。可以假设除了数字
 0 之外，这两个数字都不会以零开头。
*/

#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
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
    //翻转两个链表，然后按列竖式的方法逐个相加返回结果，缺点是需要改输入链表的结构
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head1 = reverseList(l1);
        ListNode* head2 = reverseList(l2);
        ListNode* ans = nullptr;
        int carry = 0;
        while (head1 || head2 || carry) {
            int dig_sum = carry;
            if (head1) dig_sum += head1->val;
            if (head2) dig_sum += head2->val;

            int dig_number = dig_sum % 10;
            carry = dig_sum / 10;
            ListNode* cur = new ListNode(dig_number);
            cur->next = ans;
            ans = cur;
            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
        }
        return ans;
    }

   private:
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

class Solution1 : public Solution
{
   public:
    //如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。
    //用栈
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<ListNode*> stack1, stack2;
        auto push_stack = [](stack<ListNode*>& ostack, ListNode* head) {
            while (head) {
                ostack.push(head);
                head = head->next;
            }
        };
        push_stack(stack1, l1);
        push_stack(stack2, l2);
        int carry = 0;
        ListNode* ans = nullptr;
        while (!stack1.empty() || !stack2.empty() || carry) {
            int num_dig = carry;
            if (!stack1.empty()) {
                ListNode* p1 = stack1.top();
                num_dig += p1->val;
                stack1.pop();
            }
            if (!stack2.empty()) {
                ListNode* p2 = stack2.top();
                num_dig += p2->val;
                stack2.pop();
            }
            carry = num_dig / 10;
            num_dig %= 10;
            ListNode* cur = new ListNode(num_dig);
            cur->next = ans;
            ans = cur;
        }

        return ans;
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

void uint_test(vector<int> l1_arr, vector<int> l2_arr)
{
    static int test_times = 0;
    cout << "----------test times " << test_times++ << "----------" << endl;
    Solution1 s;
    auto l1 = createList(l1_arr);
    auto l2 = createList(l2_arr);
    auto head = s.addTwoNumbers(l1, l2);
    show_node_list(head);
}

int main()
{
    uint_test(vector<int>{7, 2, 4, 3}, vector<int>{5, 6, 4});
    uint_test(vector<int>{5}, vector<int>{5});
    uint_test(vector<int>{3}, vector<int>{5});

    return 0;
}
