/*
 @filename   45.cpp
 @author     caonan
 @date       2022-04-13 12:03:46
 @reference 剑指offer专项
 @url       https://leetcode-cn.com/problems/LwUNpT/
 @brief 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。
*/
#include <assert.h>
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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> tree_queue;
        int left_val = root->val;
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int node_count = tree_queue.size();
            int is_first_num = node_count;
            while (node_count > 0) {
                auto node = tree_queue.front();
                if (is_first_num == node_count) left_val = node->val;
                if (node->left) tree_queue.push(node->left);
                if (node->right) tree_queue.push(node->right);
                tree_queue.pop();
                --node_count;
            }
        }
        return left_val;
    }
};
int main() { return 0; }
