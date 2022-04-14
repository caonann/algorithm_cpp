/*
 @filename   44.cpp
 @author     caonan
 @date       2022-04-13 08:36:03
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/hPov7L/
 @brief  给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
*/
#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode *> tree_queue;
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int line_num = tree_queue.size();
            int maxnum = INT_MIN;
            while (line_num-- > 0) {
                auto node = tree_queue.front();
                maxnum = std::max(maxnum, node->val);
                if (node->left) tree_queue.push(node->left);
                if (node->right) tree_queue.push(node->right);
                tree_queue.pop();
            }
            ans.push_back(maxnum);
        }
        return ans;
    }
};

int main() { return 0; }
