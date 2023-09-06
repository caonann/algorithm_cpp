/*
 @filename   47.cpp
 @author     caonan
 @date       2022-04-13 23:40:40
 @reference 剑指offer专项
 @url      https://leetcode-cn.com/problems/pOCWxh/
 @brief  给定一个二叉树 根节点 root ，树的每个节点的值要么是 0，要么是
1。请剪除该二叉树中所有节点的值为 0 的子树。 节点 node 的子树为 node
本身，以及所有 node 的后代。
*/
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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

class Solution {
 public:
  // 后序遍历的性质
  TreeNode *pruneTree(TreeNode *root) {
    if (!root) return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (!root->left && !root->right && root->val == 0) return nullptr;
    return root;
  }
};

class Solution1 : public Solution {
 public:
  // 非递归
  TreeNode *pruneTree(TreeNode *root) {
    auto cur = root;
    stack<TreeNode *> tree_stack;
    TreeNode *pre = nullptr;
    while (cur || !tree_stack.empty()) {
      while (cur) {
        tree_stack.push(cur);
        cur = cur->left;
      }
      cur = tree_stack.top();
      if (cur->right && cur->right != pre) {
        cur = cur->right;
      } else {
        tree_stack.pop();
        if (!cur->left && !cur->right && cur->val == 0) {
          if (tree_stack.empty()) return nullptr;
          auto parent = tree_stack.top();
          if (parent->left == cur) {
            parent->left = nullptr;
          }
          if (parent->right == cur) {
            parent->right = nullptr;
          }
        }
        pre = cur;
        cur = nullptr;
      }
    }
    return root;
  }
};

void show(TreeNode *root) {
  queue<TreeNode *> tree_queue;
  tree_queue.push(root);
  while (!tree_queue.empty()) {
    int size = tree_queue.size();
    while (size-- > 0) {
      auto node = tree_queue.front();
      if (node) {
        cout << node->val << " ";
        tree_queue.push(node->left);
        tree_queue.push(node->right);
      } else {
        cout << "#";
      }

      tree_queue.pop();
    }
    cout << endl;
  }
}

int main() {
  TreeNode *root = new TreeNode(1, new TreeNode(0), new TreeNode(1));
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(0);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(1);

  Solution1 s;
  s.pruneTree(root);
  show(root);
  return 0;
}
