/*
 @filename   49.cpp
 @author     caonan
 @date       2022-04-15 08:15:09
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/3Etpl5/
 @brief  给定一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。

每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。

叶节点 是指没有子节点的节点。
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
using namespace tree_util;
using namespace std;

class Solution
{
   public:
    int sumNumbers(TreeNode* root) { return dfs(root, 0); }

   private:
    int dfs(TreeNode* head, int val)
    {
        if (!head) return 0;
        val = val * 10 + head->val;
        if (!head->left && !head->right) return val;
        return dfs(head->left, val) + dfs(head->right, val);
    }
};
int main()
{
    Traversal t(5);
    auto root = t.getRoot();
    t.show_graph_current_tree();
    Solution s;
    int sum = s.sumNumbers(root);
    cout << "sum is " << sum << endl;
    return 0;
}
