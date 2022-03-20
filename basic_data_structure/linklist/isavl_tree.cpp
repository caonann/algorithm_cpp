/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   isavl_tree.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: isavl_tree.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Fri 17 Nov 2017 07:52:54 AM CST
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct treeNode
{
    treeNode *pLeft;
    treeNode *pRight;
    int val;
    treeNode(int ival = 0)
    {
        pLeft = NULL;
        pRight = NULL;
        val = ival;
    }
};

struct avlNode
{
    bool isavl;
    int height;
    avlNode(int h, bool bavl)
    {
        isavl = bavl;
        height = h;
    }
};

avlNode getHeight(treeNode *pHead, int level)
{
    if (pHead == NULL)
    {
        return avlNode(level, true);
    }

    avlNode retleft = getHeight(pHead->pLeft, level + 1);
    cout << "leftheight" << retleft.height << endl;

    if (!retleft.isavl)
    {
        return avlNode(level, false);
    }

    avlNode retright = getHeight(pHead->pRight, level + 1);

    if (!retright.isavl)
    {
        return avlNode(level, false);
    }

    cout << "rightheight" << retright.height << endl;

    if (abs(retleft.height - retright.height) > 1)
    {
        cout << ">1" << endl;
        return avlNode(std::max(retleft.height, retright.height), false);
    }
    else
    {
        return avlNode(std::max(retleft.height, retright.height), true);
    }
}

bool isAvl(treeNode *pHead)
{
    avlNode ret = getHeight(pHead, 0);
    return ret.isavl;
}



int main()
{
    treeNode *p = new treeNode(1);
    p->pLeft = new treeNode(2);
    p->pRight = new treeNode(3);
    p->pLeft->pLeft = new treeNode(2);
    p->pLeft->pLeft->pRight = new treeNode(2);
    p->pLeft->pLeft->pLeft = new treeNode(2);
    p->pLeft->pLeft->pLeft->pLeft = new treeNode(5);
    treeNode *p2 = new treeNode(1);
    p2->pLeft = new treeNode(2);
    p2->pRight = new treeNode(3);
    p2->pLeft->pLeft = new treeNode(54);
    p2->pLeft->pRight = new treeNode(6);
    p2->pLeft->pLeft->pLeft = new treeNode(7);
    bool ret = isAvl(p2);
    cout << "is " << ret << endl;
    return 0;
}

