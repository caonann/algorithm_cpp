/*
 @filename   1382.balanceBST.cpp
 @author     caonan
 @date       2022-04-23 13:29:44
 @reference     leetcode
 @url      https://leetcode-cn.com/problems/balance-a-binary-search-tree/
 @brief
给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。如果有多种构造方法，请你返回任意一种。
如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。
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
    TreeNode* balanceBST(TreeNode* root)
    {
        dfs(root);
        return build(0, inorder_arr.size() - 1);
    }

   private:
    TreeNode* build(int left, int right)
    {
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(inorder_arr[mid]);
        if (left <= mid - 1) {
            root->left = build(left, mid - 1);
        }

        if (mid + 1 <= right) {
            root->right = build(mid + 1, right);
        }
        return root;
    }
    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->left);
        inorder_arr.push_back(root->val);
        dfs(root->right);
    }
    vector<int> inorder_arr;
};
int main() { return 0; }
