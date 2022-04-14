/*
 @filename   43.cpp
 @author     caonan
 @date       2022-04-13 07:45:23
 @reference     剑指offer专项
 @url      https://leetcode-cn.com/problems/NaqhDT/
 @brief  完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大，第 n 层有
2n-1 个节点）的，并且所有的节点都尽可能地集中在左侧。

设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：

CBTInserter(TreeNode root) 使用根节点为 root 的给定树初始化该数据结构；
CBTInserter.insert(int v)  向树中插入一个新节点，节点类型为 TreeNode，值为 v
。使树保持完全二叉树的状态，并返回插入的新节点的父节点的值； CBTInserter.get_root() 将返回树的根节点。
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

class CBTInserter
{
   public:
    CBTInserter(TreeNode *root) : root_(root) { init_tree_node_que(root_); }

    int insert(int v)
    {
        auto cur_node = tree_nodes_queue_.front();
        int val = cur_node->val;
        if (cur_node->left) {
            cur_node->right = new TreeNode(v);
            tree_nodes_queue_.push(cur_node->right);
            tree_nodes_queue_.pop();
        } else {
            cur_node->left = new TreeNode(v);
            tree_nodes_queue_.push(cur_node->left);
        }
        return val;
    }

    TreeNode *get_root() { return root_; }

   private:
    void init_tree_node_que(TreeNode *node)
    {
        if (!node) return;
        tree_nodes_queue_.push(node);
        while (!tree_nodes_queue_.empty()) {
            auto node = tree_nodes_queue_.front();
            if (node->left) {
                tree_nodes_queue_.push(node->left);
            } else {
                break;
            }
            if (node->right) {
                tree_nodes_queue_.push(node->right);
            } else {
                break;
            }
            tree_nodes_queue_.pop();
        }
    }
    queue<TreeNode *> tree_nodes_queue_;
    TreeNode *root_{nullptr};
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

int main() { return 0; }
