/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   longsetsumtree.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: longsetsumtree.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Wed 15 Nov 2017 11:51:08 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
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

int preOrder(treeNode *pHead, int k, int level, int sum, int len, map<int, int> &arrmap)
{
    if (pHead == NULL)
    {
        return len;
    }

    sum += pHead->val;

    if (arrmap.count(sum - k))
    {
        int tmplen = arrmap[sum - k];
        len = level - tmplen > len ? level - tmplen : len;
    }

    if (!arrmap.count(sum))
    {
        arrmap.insert(make_pair(sum, level));
    }

    len = preOrder(pHead->pLeft, k, level + 1, sum, len, arrmap);
    len = preOrder(pHead->pRight, k, level + 1, sum, len, arrmap);

    if (arrmap[sum] == level)
    {
        arrmap.erase(sum);
    }

    return len;
}

int GetLongestSumTree(treeNode *pHead, int k)
{
    if (pHead == NULL)
    {
        return 0;
    }

    map<int, int> arrmap;
    arrmap.insert(make_pair(0, -1));
    return preOrder(pHead, k, 0, 0, 0, arrmap);
}


int main()
{
    // 1,2,2,2,5
    treeNode *p = new treeNode(1);
    p->pLeft = new treeNode(2);
    p->pRight = new treeNode(3);
    p->pLeft->pLeft = new treeNode(2);
    p->pLeft->pLeft->pRight = new treeNode(2);
    p->pLeft->pLeft->pLeft = new treeNode(2);
    p->pLeft->pLeft->pLeft->pLeft = new treeNode(5);
    cout << GetLongestSumTree(p, 7) << endl;
    return 0;
}

