/*
 @filename   23.cpp
 @author     caonan
 @date       2022-04-06 07:54:04
 @reference  剑指offer专项
 @url       https://leetcode-cn.com/problems/3u1WK4/
 @brief     给定两个单链表的头节点 headA 和 headB ，请找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回
 null
*/

#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
   public:
    //用hash表的方式，时间复杂度o(n) 空间o(n)
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (!headA || !headB) return nullptr;
        unordered_set<ListNode*> hash_set;
        while (headA) {
            hash_set.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (hash_set.find(headB) != hash_set.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

class Solution1 : public Solution
{
   public:
    //双指针，时间o(n) 空间o(1)
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int lenA = 0, lenB = 0;
        auto calcLenOfList = [](ListNode* head, int& len) {
            while (head) {
                len++;
                head = head->next;
            }
        };
        calcLenOfList(headA, lenA);
        calcLenOfList(headB, lenB);
        ListNode* head_longer = lenA > lenB ? headA : headB;
        int n = std::abs(lenA - lenB);
        while (head_longer && n--) {
            head_longer = head_longer->next;
        }
        ListNode* head_shorter = lenA <= lenB ? headA : headB;
        while (head_longer) {
            if (head_shorter == head_longer) return head_shorter;
            head_shorter = head_shorter->next;
            head_longer = head_longer->next;
        }
        return nullptr;
    }
};

class Solution2 : public Solution
{
   public:
    //用栈，从尾部抛出，直到有相同的，时间o(n),空间o(n)
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (!headA || !headB) return nullptr;
        stack<ListNode*> stackA, stackB;
        auto push_stack = [](stack<ListNode*>& ostack, ListNode* head) {
            while (head) {
                ostack.push(head);
                head = head->next;
            }
        };

        ListNode* pre = nullptr;
        push_stack(stackA, headA);
        push_stack(stackB, headB);
        while (!stackA.empty() && !stackB.empty()) {
            ListNode* node_a = stackA.top();
            ListNode* node_b = stackB.top();
            if (node_a != node_b) {
                return pre;
            }
            pre = node_a;
            stackA.pop();
            stackB.pop();
        }
        return pre ? pre : nullptr;
    }
};

class Solution3 : public Solution
{
   public:
    //将一个链表的头和两个相交链表的尾巴连在一起，就转化为寻找单链表有没有环，并找到环入口的问题了
    //这种方法改变了输入链表，如果是工程上，其实并不推荐
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (!headA || !headB) return nullptr;
        ListNode* tmp = headA;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = headB;
        ListNode *fast = headA, *slow = headA;
        while (fast) {
            if (!fast->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                fast = headA;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                //恢复输入链表
                tmp->next = nullptr;
                return fast;
            }
        }
        return nullptr;
    }
};

// merge arr2 to arr1
pair<ListNode*, ListNode*> createMergeList(const vector<int>& arr1, const vector<int>& arr2, int arr1_val)
{
    if (arr1.empty() || arr2.empty()) return make_pair(nullptr, nullptr);
    ListNode* head1 = new ListNode(arr1[0]);
    ListNode* tmp = head1;
    ListNode* insert_pos = head1;
    for (int i = 1; i < arr1.size(); i++) {
        tmp->next = new ListNode(arr1[i]);
        tmp = tmp->next;
        if (arr1[i] == arr1_val) {
            insert_pos = tmp;
        }
    }
    ListNode* head2 = new ListNode(arr2[0]);
    tmp = head2;
    for (int i = 1; i < arr2.size(); i++) {
        tmp->next = new ListNode(arr2[i]);
        tmp = tmp->next;
    }
    tmp->next = insert_pos;
    return make_pair(head1, head2);
}

void print_one_list(ListNode* head)
{
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    printf("\n");
}

void uint_test(const vector<int>& arr1, const vector<int>& arr2, int arr1_val)
{
    static int test_times = 0;
    cout<<"----------test times "<<test_times++<<"----------"<<endl;
    Solution3 s;
    auto list_headers = createMergeList(arr1, arr2, arr1_val);
    print_one_list(list_headers.first);
    print_one_list(list_headers.second);
    auto p = s.getIntersectionNode(list_headers.first, list_headers.second);
    if (p) {
        cout << "value is " << p->val << endl;
    } else {
        cout << "p is nullptr" << endl;
    }
}
int main()
{
    uint_test(vector<int>{1, 2, 3, 4, 5, 6, 7, 8}, vector<int>{9, 10, 11, 12, 13}, 5);
    uint_test(vector<int>{1}, vector<int>{2,3}, 1);
    uint_test(vector<int>{1}, vector<int>{2}, 1);
    return 0;
}
