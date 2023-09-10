/*
 @filename   binary_tree/236.lowestCommonAncestor.cpp
 @author     caonan
 @date       2023-09-09 14:30:23
 @reference  leetcode
 @url      https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
 @brief
*/
#include <cassert>
#include <climits>
#include <cstdio>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  // 用额外空间来记录每个节点的父节点指针，从而找到公共祖先
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    parent_map_[root] = nullptr;
    dfs(root);
    unordered_set<TreeNode*> path_history;
    while (parent_map_.find(p) != parent_map_.end()) {
      path_history.insert(p);
      p = parent_map_[p];
    }

    while (parent_map_.find(q) != parent_map_.end()) {
      if (path_history.find(q) != path_history.end()) {
        return q;
      }
      q = parent_map_[q];
    }
    return nullptr;
  }

  void dfs(TreeNode* root) {
    if (root == nullptr) {
      return;
    }

    if (root->left) {
      parent_map_[root->left] = root;
      dfs(root->left);
    }
    if (root->right) {
      parent_map_[root->right] = root;
      dfs(root->right);
    }
  }

 private:
  unordered_map<TreeNode*, TreeNode*> parent_map_;
};

int main() { return 0; }
