/*
 @filename   54.cpp
 @author     caonan
 @date       2022-04-19 00:56:38
 @reference    剑指offer专项
 @url      https://leetcode-cn.com/problems/w6cpku/
 @brief  给定一个二叉搜索树，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。
提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
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
    TreeNode* convertBST(TreeNode* root)
    {
        dfs(root);
        return root;
    }

   private:
    void dfs(TreeNode* node)
    {
        if (!node) return;
        dfs(node->right);
        node->val += sum_;
        sum_ = node->val;
        dfs(node->left);
    }
    int sum_{0};
};
int main() { return 0; }
