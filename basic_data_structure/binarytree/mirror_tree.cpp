/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   mirror_tree.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
#include "common/define.h"
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};

void Mirror(TreeNode *pRoot)
{
    if (pRoot == NULL)
    {
        return;
    }

    TreeNode *tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;

    if (pRoot->left)
    {
        Mirror(pRoot->left);
    }

    if (pRoot->right)
    {
        Mirror(pRoot->right);
    }
}

void show_tree(TreeNode *root)
{
    if (!root)
    {
        cout << endl;
        return;
    }

    cout << root->val << " ";

    if (root->left)
    {
        show_tree(root->left);
    }

    if (root->right)
    {
        show_tree(root->right);
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    show_tree(root);
    Mirror(root);
    show_tree(root);
    return 0;
}