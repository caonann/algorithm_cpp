/*
 @filename   46.cpp
 @author     caonan
 @date       2022-04-13 12:18:40
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/WNC0Lk/
 @brief  给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode *> tree_queue;
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            while (size-- > 0) {
                auto node = tree_queue.front();
                if (size == 0) ans.push_back(node->val);
                if (node->left) tree_queue.push(node->left);
                if (node->right) tree_queue.push(node->right);
                tree_queue.pop();
            }
        }
        return ans;
    }
};
int main() { return 0; }
