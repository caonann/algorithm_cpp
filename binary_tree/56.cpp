/*
 @filename   56.cpp
 @author     caonan
 @date       2022-04-22 16:32:30
 @reference  剑指offer专项
 @url      https://leetcode-cn.com/problems/opLdQZ/
 @brief  给定一个二叉搜索树的 根节点 root 和一个整数 k , 请判断该二叉搜索树中是否存在两个节点它们的值之和等于 k
 。假设二叉搜索树中节点的值均唯一
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
#include <unordered_set>
#include <vector>

#include "traverse.h"
using namespace std;
using namespace tree_util;

//创建一个二叉树中序遍历的迭代器
class TreeIterator
{
   public:
    explicit TreeIterator(TreeNode* root)
    {
        while (root) {
            node_stack_.push(root);
            root = root->left;
        }
    }
    TreeIterator() = default;
    TreeNode* next()
    {
        if (node_stack_.empty()) return nullptr;
        auto cur = node_stack_.top();
        node_stack_.pop();
        auto tmp = cur->right;
        while (tmp) {
            node_stack_.push(tmp);
            tmp = tmp->left;
        }
        return cur;
    }

   protected:
    stack<TreeNode*> node_stack_;
};

class TreeIteratorReverse : public TreeIterator
{
   public:
    explicit TreeIteratorReverse(TreeNode* root)
    {
        while (root) {
            node_stack_.push(root);
            root = root->right;
        }
    }

    TreeNode* next()
    {
        if (node_stack_.empty()) return nullptr;
        auto cur = node_stack_.top();
        node_stack_.pop();
        auto tmp = cur->left;
        while (tmp) {
            node_stack_.push(tmp);
            tmp = tmp->right;
        }
        return cur;
    }
};

//用双向迭代器的方式比较
class Solution
{
   public:
    bool findTarget(TreeNode* root, int k)
    {
        auto right = new TreeIteratorReverse(root);
        auto left = new TreeIterator(root);
        auto node_r = right->next();
        auto node_l = left->next();
        while (node_r != node_l) {
            // cout << "left val " << node_l->val << " right val " << node_r->val << endl;
            if (node_r->val + node_l->val == k) {
                return true;
            } else if (node_r->val + node_l->val > k) {
                node_r = right->next();
            } else {
                node_l = left->next();
            }
        }
        return false;
    }
};

//用hash表存值
class Solution1 : public Solution
{
   public:
    bool findTarget(TreeNode* root, int k)
    {
        k_ = k;
        return dfs(root);
    }

   private:
    bool dfs(TreeNode* root)
    {
        if (!root) return false;
        if (hash_set.find(root->val) != hash_set.end()) {
            return true;
        } else {
            hash_set.insert(k_ - root->val);
        }

        return dfs(root->left) || dfs(root->right);
    }
    int k_;
    unordered_set<int> hash_set;
};

//非递归方式
class Solution2 : public Solution
{
   public:
    bool findTarget(TreeNode* root, int k)
    {
        unordered_set<int> hash_set;
        stack<TreeNode*> tree_stack;
        auto cur = root;
        TreeNode* pre = nullptr;
        while (cur || !tree_stack.empty()) {
            while (cur) {
                tree_stack.push(cur);
                cur = cur->left;
            }
            cur = tree_stack.top();
            if (cur->right != pre && cur->right) {
                cur = cur->right;
            } else {
                pre = cur;
                int val = cur->val;
                if (hash_set.find(val) != hash_set.end()) {
                    return true;
                } else {
                    hash_set.insert(k - val);
                }

                cur = nullptr;
                tree_stack.pop();
            }
        }
        return false;
    }
};

int main()
{
    Traversal t(10);
    t.show_graph_current_tree();
    auto root = t.getRoot();
    Solution s;
    cout << s.findTarget(root, 6) << endl;
    cout << s.findTarget(root, 66) << endl;
    cout << s.findTarget(root, 10) << endl;
    return 0;
}
