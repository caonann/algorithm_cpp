/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   reverse_list.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
// ·´×ªÁ´±í
#include<iostream>
using namespace std;
struct NodeList
{
    NodeList(int nval): val(nval) {}
    NodeList *pNext;
    int val;
};

NodeList *reverselist(NodeList *pHead)
{
    NodeList *pPre = nullptr;
    NodeList *pLast = pHead;

    while (pLast != nullptr)
    {
        pLast = pHead->pNext;
        pHead->pNext = pPre;

        if (pLast == nullptr)
        {
            return pHead;
        }

        pPre = pHead;
        pHead = pLast;
    }

    return pLast;
}

void show_list(NodeList *phead)
{
    while (phead != nullptr)
    {
        cout << phead->val << " ";
        phead = phead->pNext;
    }

    cout << endl;
}
int main()
{
    NodeList *phead = new NodeList(1);
    /*phead->pNext = new NodeList(2);
    phead->pNext->pNext = new NodeList(3);
    phead->pNext->pNext->pNext = new NodeList(4);*/
    show_list(phead);
    phead = reverselist(phead);
    show_list(phead);
    return 0;
}