/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   1-4_ChangeBinaryTree.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main(int argc, const char **argv)
{
    cout << "hello" << endl;
    TreeNode *tree = new TreeNode(2);
    tree->left = new TreeNode(3);
    return 0;
}