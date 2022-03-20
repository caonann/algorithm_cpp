/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   longest_search_tree.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: longest_search_tree.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Wed 22 Nov 2017 12:15:47 AM CST
 ************************************************************************/

#include <iostream>
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

struct ReturnType
{
    int height;
    int distance;
    ReturnType(int h, int d)
    {
        height = h;
        distance = d;
    }
};

ReturnType getMaxDistance(treeNode *pHead)
{
    if (NULL == pHead)
    {
        return ReturnType(0, 0);
    }

    ReturnType leftInfo = getMaxDistance(pHead->pLeft);
    ReturnType rightInfo = getMaxDistance(pHead->pRight);
    int maxdis = leftInfo.height + rightInfo.height + 1;
    int pl = leftInfo.distance;
    int pr = rightInfo.distance;
    int myself = std::max(leftInfo.height, rightInfo.height) + 1;
    int dismax = std::max(std::max(pl, pr), maxdis);
    return ReturnType(myself, dismax);
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
    ReturnType ret = getMaxDistance(p);
    cout << ret.distance << " " << ret.height << endl;
    return 0;
}

