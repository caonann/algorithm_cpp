
/*************************************************************************
    > File Name: 110.BalancedBinaryTree.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 15 Jun 2019 04:23:52 AM UTC
 ************************************************************************/

#include <iostream>
#include<cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    typedef struct BalanceParam
    {
        BalanceParam(): isAvl(true), height(0) {}
        bool isAvl;
        int height;
    } BalanceParamInfo;

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        BalanceParamInfo left_tree = GetHeight(root->left, 1);

        if (!left_tree.isAvl)
        {
            return false;
        }

        BalanceParamInfo right_tree = GetHeight(root->right, 1);

        if (!right_tree.isAvl)
        {
            return false;
        }

        if (std::abs(left_tree.height - right_tree.height) <= 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    BalanceParamInfo GetHeight(TreeNode *head, int height)
    {
        if (head == nullptr)
        {
            BalanceParamInfo balance;
            balance.height = height;
            return balance;
        }

        BalanceParamInfo left = GetHeight(head->left, height + 1);

        if (!left.isAvl)
        {
            BalanceParamInfo balance;
            balance.isAvl = false;
            return balance;
        }

        BalanceParamInfo right = GetHeight(head->right, height + 1);

        if (!right.isAvl)
        {
            BalanceParamInfo balance;
            balance.isAvl = false;
            return balance;
        }

        if (std::abs(left.height - right.height) <= 1)
        {
            BalanceParamInfo balance;
            balance.height = left.height > right.height ? left.height : right.height;
            balance.isAvl = true;
            return balance;
        }
        else
        {
            BalanceParamInfo balance;
            balance.height = left.height > right.height ? left.height : right.height;
            balance.isAvl = false;
            return balance;
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    // root->right = new TreeNode(0);
    Solution s;
    bool ret = s.isBalanced(root);

    if (ret)
    {
        cout << "balanced" << endl;
    }
    else
    {
        cout << "not balanced" << endl;
    }

    return 0;
}

