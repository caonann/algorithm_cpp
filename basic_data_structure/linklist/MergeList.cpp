/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   MergeList.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: MergeList.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Wed 11 Apr 2018 11:26:14 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {}
};


ListNode *Merge1(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == NULL)
    {
        return pHead2;
    }

    if (pHead2 == NULL)
    {
        return pHead1;
    }

    ListNode *mergehead;

    if (pHead1->val < pHead2->val)
    {
        mergehead = pHead1;
        mergehead->next = Merge1(pHead1->next, pHead2);
    }
    else
    {
        mergehead = pHead2;
        mergehead->next = Merge1(pHead1, pHead2->next);
    }

    return mergehead;
}

ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == NULL)
    {
        return pHead2;
    }

    if (pHead2 == NULL)
    {
        return pHead1;
    }

    ListNode *current = NULL;
    ListNode *mergehead = NULL;

    while (pHead1 != NULL && pHead2 != NULL)
    {
        if (pHead1->val < pHead2->val)
        {
            if (mergehead == NULL)
            {
                mergehead = pHead1;
                current = mergehead;
            }
            else
            {
                current->next = pHead1;
                current = current->next;
            }

            pHead1 = pHead1->next;
        }
        else
        {
            if (mergehead == NULL)
            {
                mergehead = pHead2;
                current = mergehead;
            }
            else
            {
                current->next = pHead2;
                current = current->next;
            }

            pHead2 = pHead2->next;
        }
    }

    if (pHead1)
    {
        current->next = pHead1;
    }

    if (pHead2)
    {
        current->next = pHead2;
    }

    return mergehead;
}


void show(ListNode *p)
{
    while (p)
    {
        cout << p->val << endl;
        p = p->next;
    }
}
int main()
{
    ListNode *p1 = new ListNode(10);
    p1->next = new ListNode(11);
    p1->next->next = new ListNode(13);
    ListNode *p2 = new ListNode(4);
    p2->next = new ListNode(5);
    p2->next->next = new ListNode(12);
    ListNode *p = Merge(p1, p2);
    show(p);
    return 0;
}

