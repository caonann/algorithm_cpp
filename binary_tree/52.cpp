/*
 @filename   52.cpp
 @author     caonan
 @date       2022-04-18 11:27:37
 @reference    剑指offer专项
 @url      https://leetcode-cn.com/problems/NYBBNL/
 @brief  给你一棵二叉搜索树，请 按中序遍历
 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "traverse.h"
using namespace std;
using namespace tree_util;

class Solution
{
   public:
    TreeNode* increasingBST(TreeNode* root)
    {
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        TreeNode* first = pre;
        stack<TreeNode*> tree_stack;
        while (cur || !tree_stack.empty()) {
            while (cur) {
                tree_stack.push(cur);
                cur = cur->left;
            }
            cur = tree_stack.top();
            tree_stack.pop();

            if (!pre) {
                first = cur;
            } else {
                pre->right = cur;
            }
            pre = cur;
            cur->left = nullptr;
            cur = cur->right;
        }
        return first;
    }
};

//递归
class Solution1 : public Solution
{
   public:
    TreeNode* increasingBST(TreeNode* root)
    {
        pre = new TreeNode(-1);
        dfs(root);
        return first;
    }

   private:
    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->left);
        if (!first) first = root;
        pre->right = root;
        root->left = nullptr;
        pre = root;
        dfs(root->right);
    }
    TreeNode* pre;
    TreeNode* first{nullptr};
};

int main() { return 0; }
