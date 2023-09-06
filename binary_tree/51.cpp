/*
 @filename   51.cpp
 @author     caonan
 @date       2022-04-15 11:37:20
 @reference 剑指offer专项
 @url      https://leetcode-cn.com/problems/jC7MId/
 @brief  路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中
至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给定一个二叉树的根节点 root ，返回其 最大路径和，即所有路径上节点值之和的最大值。
*/
#include <assert.h>
#include <limits.h>
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
    int maxPathSum(TreeNode* root)
    {
        dfs(root);
        return max_;
    }

   private:
    int max_{INT_MIN};
    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int left_max = std::max(dfs(root->left), 0);
        int right_max = std::max(dfs(root->right), 0);
        int child_max = left_max > right_max ? left_max : right_max;
        int sum = left_max + right_max + root->val;
        max_ = std::max(max_, sum);
        return child_max + root->val;
    }
};

int main()
{
    Traversal t(10);
    // t.show_graph_current_tree();
    // t.show_val_order(Traversal::preorder);
    auto root = t.getRoot();
    Solution s;
    int max = s.maxPathSum(root);
    cout << "max is " << max << endl;
    return 0;
}
