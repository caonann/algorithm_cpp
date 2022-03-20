/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   rebuild_tree.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: rebuild_tree.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Wed 04 Apr 2018 12:00:02 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include "common/define.h"
using namespace std;

TreeNode *ConstructTree(vector<int> &pre, vector<int> &vin, int ipre_b, int ipre_e, int ivin_b, int ivin_e)
{
    TreeNode *root = new TreeNode(pre[ipre_b]);

    // printf("%d %d %d %d\n", ipre_b, ipre_e, ivin_b, ivin_e);
    if (ipre_b == ipre_e)
    {
        if (ivin_b == ivin_e && pre[ipre_b] == vin[ivin_b])
        {
            return root;
        }
        else
        {
            // error throw err
            cout << "error tree" << endl;
            return NULL;
        }
    }

    int pos = -1;

    for (int i = ivin_b; i <= ivin_e; i++)
    {
        if (vin[i] == pre[ipre_b])
        {
            pos = i;
        }
    }

    if (-1 == pos)
    {
        cout << "err tree" << endl;
        return NULL;
    }

    int left_len = pos - ivin_b;
    int right_len = ivin_e - ivin_b - left_len;

    // return NULL;

    if (left_len > 0)
    {
        root->left = ConstructTree(pre, vin,
                                   ipre_b + 1,
                                   ipre_b + left_len,
                                   ivin_b,
                                   ivin_b + left_len - 1);
    }

    if (right_len > 0)
    {
        root->right = ConstructTree(pre, vin,
                                    ipre_b + left_len + 1,
                                    ipre_e,
                                    ivin_b + left_len + 1,
                                    ivin_e);
    }

    return root;
}

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    return ConstructTree(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
}

void show(TreeNode *root)
{
    if (root)
    {
        cout << root->val << endl;

        if (root->left)
        {
            show(root->left);
        }

        if (root->right)
        {
            show(root->right);
        }
    }
}
int main()
{
    // [1,2,3,4,5,6,7],[3,2,4,1,6,5,7] [1,2,4,3,5,6],[4,2,1,5,3,6]
    vector<int> pre = { 1, 2, 4, 3, 5, 6 };
    vector<int> vin = { 4, 2, 1, 5, 3, 6 };
    TreeNode *root = reConstructBinaryTree(pre, vin);
    show(root);
    return 0;
}

