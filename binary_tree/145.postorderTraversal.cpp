/*
 @filename   145.postorderTraversal.cpp
 @author     caonan
 @date       2022-04-14 07:39:59
 @reference     leetcode 145
 @url      https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 @brief  给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "traverse.h"
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
   public:
    vector<int> postorderTraversal(TreeNode *root) {}
};
int main() { return 0; }
