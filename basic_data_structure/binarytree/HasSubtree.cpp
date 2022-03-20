/*************************************************************************
    > File Name: HasSubtree.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 14 Apr 2018 01:03:11 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {}
};

bool compare(TreeNode *p1, TreeNode *p2)
{
    bool ret = true;

    if (p1 && p2)
    {
        if (p1->val != p2->val)
        {
            return false;
        }

        if (p2->left)
        {
            ret &= compare(p1->left, p2->left);
        }

        if (p2->right)
        {
            ret &= compare(p1->right, p2->right);
        }
    }

    if (p1 == NULL && p2 != NULL)
    {
        return false;
    }

    return ret;
}


bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (pRoot1 == NULL || pRoot2 == NULL)
    {
        return false;
    }

    if (pRoot1->val == pRoot2->val)
    {
        if (compare(pRoot1, pRoot2))
        {
            return true;
        }
    }

    bool bleft = false;
    bool bright = false;

    if (pRoot1->left)
    {
        bleft |= HasSubtree(pRoot1->left, pRoot2);
    }

    if (pRoot1->right)
    {
        bright |= HasSubtree(pRoot1->right, pRoot2);
    }

    return (bleft || bright);
}



int main()
{
    TreeNode *p1 = new TreeNode(1);
    p1->left = new struct TreeNode(2);
    p1->right = new struct TreeNode(3);
    p1->left->left = new struct TreeNode(4);
    p1->left->right = new struct TreeNode(5);
    p1->left->left->left = new struct TreeNode(6);
    TreeNode *p2 = new TreeNode(2);
    p2->left = new struct TreeNode(4);
    p2->right = new struct TreeNode(5);
    cout << HasSubtree(p1, p2) << endl;
    return 0;
}

