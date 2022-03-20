/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   common_define.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/
/*************************************************************************
    > File Name: common_define.h
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 03 Aug 2019 03:26:23 AM UTC
 ************************************************************************/

#include "common_define.h"
namespace comm
{
int *bubbleSort(int *A, int n)
{
    if (A == NULL || n < 0)
    {
        return NULL;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }

    return A;
}

TreeNode *createTree(vector<int> &arr)
{
    if (arr.empty())
    {
        return nullptr;
    }

    vector<TreeNode *> treenode_arr;

    for (auto &v : arr)
    {
        treenode_arr.emplace_back(new TreeNode(v));
    }

    int len = static_cast<int>(arr.size());

    for (int i = 0; i < len / 2 - 1; i++)
    {
        int left_idx = 2 * i + 1;
        int right_idx = 2 * i + 2;
        TreeNode *node = treenode_arr[i];
        node->left = treenode_arr[left_idx];

        if (right_idx < len)
        {
            node->right = treenode_arr[right_idx];
        }
    }

    return treenode_arr[0];
}

}


int RandomUtils::getInt(int start,int end)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<int> u(start, end);
    return u(e);
}

double RandomUtils::getDouble(double start,double end)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_real_distribution<double> u(start,end);
    return u(e);
}