/*
 @filename   27.cpp
 @author     caonan
 @date       2022-04-07 07:48:00
 @reference  剑指offer专项
 @url       https://leetcode-cn.com/problems/aMhZSa/
 @brief     给定一个链表的 头节点 head ，请判断其是否为回文链表。
如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。
*/

#include <assert.h>
#include <stdio.h>
#include <time.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
   public:
    bool isPalindrome(ListNode *head)
    {
        int n = 0;
        auto p = head;
        while (p) {
            ++n;
            p = p->next;
        }
        auto getHead = [](ListNode *head, int n) -> ListNode * {
            int count = n / 2 - 1;
            while (count-- > 0 && head) {
                head = head->next;
            }
            return head ? head->next : head;
        };
        auto p2 = getHead(head, n);
        p2 = reverseList(p2);
        while (head && p2) {
            if (head->val != p2->val) return false;
            head = head->next;
            p2 = p2->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
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
    //用快慢指针找到链表的中间节点，然后反转比较
    bool isPalindrome(ListNode *head)
    {
        ListNode dummy(-1, head);
        ListNode *fast = &dummy, *slow = &dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto p = reverseList(slow->next);
        slow->next = nullptr;
        while (head && p) {
            if (head->val != p->val) return false;
            head = head->next;
            p = p->next;
        }
        return true;
    }
};

ListNode *createPalindromeList(vector<int> arr, bool odd)
{
    ListNode dummy(-1);
    auto phead = &dummy;
    for (int i = 0; i < arr.size(); i++) {
        phead->next = new ListNode(arr[i]);
        phead = phead->next;
    }

    int len = odd ? arr.size() - 2 : arr.size() - 1;
    for (int i = len; i >= 0; --i) {
        phead->next = new ListNode(arr[i]);
        phead = phead->next;
    }

    return dummy.next;
}

ListNode *createRandomList(vector<int> arr)
{
    srand((unsigned int)time(0));
    random_shuffle(arr.begin(), arr.end());
    ListNode dummy(-1);
    auto phead = &dummy;
    for (int i = 0; i < arr.size(); i++) {
        phead->next = new ListNode(arr[i]);
        phead = phead->next;
    }
    return dummy.next;
}

void printNodeList(ListNode *node)
{
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

void uint_test(vector<int> arr, bool odd)
{
    static int test_times = 0;
    cout << "----------test times " << test_times++ << "----------" << endl;
    auto p = createPalindromeList(arr, odd);
    printNodeList(p);
    Solution1 s;
    assert(s.isPalindrome(p));
}

void uint_test_false(vector<int> arr)
{
    static int test_times = 0;
    cout << "----------test times " << test_times++ << "----------" << endl;
    auto p = createRandomList(arr);
    printNodeList(p);
    Solution1 s;
    assert(!s.isPalindrome(p));
}

int main()
{
    uint_test(vector<int>{1, 2, 3, 4}, true);
    uint_test(vector<int>{1, 2, 3, 4}, false);
    uint_test(vector<int>{1}, true);
    uint_test_false(vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
    uint_test_false(vector<int>{1, 2});
    return 0;
}
