/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   FindKthToTail.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: FindKthToTail.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Wed 11 Apr 2018 12:00:24 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
{
    if (NULL == pListHead || k == 0)
    {
        return NULL;
    }

    ListNode *pFast = pListHead;

    for (int i = 0; i < k - 1; i++)
    {
        pFast = pFast->next;

        if (pFast == NULL)
        {
            return NULL;
        }
    }

    while (pFast->next)
    {
        pListHead = pListHead->next;
        pFast = pFast->next;
    }

    return pListHead;
}

int main()
{
    return 0;
}

