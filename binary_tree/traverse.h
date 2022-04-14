/*
 @filename   traverse.cpp
 @author     caonan
 @date       2022-04-13 23:39:37
 @reference
 @url
 @brief  二叉树基本遍历练习
*/
#ifndef _TRAVERSE_H_
#define _TRAVERSE_H_
#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//这里先只以节点val为int类型的二叉树为例子，按照遍历顺序输出arr数组
namespace tree_util
{
class Traversal
{
   public:
    enum TraverseType {
        inorder,
        preorder,
        postorder,
        inorderNoneRecursion,
        preorderNoneRecursion,
        postorderNoneRecursion,
        bfs
    };
    // default create increasing complete binary tree
    explicit Traversal(int node_count)
    {
        assert(node_count >= 0);
        if (!node_count) return;
        root_ = new TreeNode(0);
        queue<TreeNode*> tree_queue;
        tree_queue.push(root_);
        for (int i = 1; i < node_count; i += 2) {
            auto node = tree_queue.front();
            node->left = new TreeNode(i);
            tree_queue.push(node->left);
            if (i + 1 < node_count) {
                node->right = new TreeNode(i + 1);
                tree_queue.push(node->right);
            }
            tree_queue.pop();
        }
    }
    explicit Traversal(const vector<int>& node_val_arr) { return; }
    ~Traversal()
    {
        if (!root_) return;
        queue<TreeNode*> tree_queue;
        tree_queue.push(root_);
        while (!tree_queue.empty()) {
            auto node = tree_queue.front();
            if (node->left) tree_queue.push(node->left);
            if (node->right) tree_queue.push(node->right);
            delete node;
            tree_queue.pop();
        }
    }

    void show_graph_current_tree(TreeNode* head = nullptr)
    {
        cout << "----------show_graph_current_tree----------" << endl;
        if (!head) head = root_;
        queue<TreeNode*> tree_queue;
        tree_queue.push(head);

        while (!tree_queue.empty()) {
            int size = tree_queue.size();
            while (size-- > 0) {
                auto node = tree_queue.front();
                cout << node->val << " ";
                if (node->left) tree_queue.push(node->left);
                if (node->right) tree_queue.push(node->right);
                tree_queue.pop();
            }
            cout << endl;
        }
    }

    void show_val_order(TraverseType type = bfs)
    {
        auto printList = [](const vector<int>& arr) {
            for (auto v : arr) cout << v << " ";
            cout << endl;
        };
        vector<int> ans;
        switch (type) {
        case inorder: {
            cout << "----------inorderTraversalRecursion----------" << endl;
            ans = inorderTraversalRecursion();
        } break;
        case preorder: {
            cout << "----------preorderTraversalRecursion----------" << endl;
            ans = preorderTraversalRecursion();
        } break;
        case postorder: {
            cout << "----------postorderTraversalRecursion----------" << endl;
            ans = postorderTraversalRecursion();
        } break;
        case inorderNoneRecursion: {
            cout << "----------inorderTraversal----------" << endl;
            ans = inorderTraversal();
        } break;
        case preorderNoneRecursion: {
            cout << "----------preorderTraversal----------" << endl;
            ans = preorderTraversal();
        } break;
        case postorderNoneRecursion: {
            cout << "----------postorderTraversal----------" << endl;
            ans = postorderTraversal();
        } break;
        case bfs: {
            cout << "----------bfsTraversal----------" << endl;
            ans = bfsTraversal();
        } break;
        default:
            break;
        }

        printList(ans);
    }

    //广度遍历
    vector<int> bfsTraversal()
    {
        vector<int> ans;
        auto head = root_;
        if (!head) return ans;
        queue<TreeNode*> tree_queue;
        tree_queue.push(head);
        while (!tree_queue.empty()) {
            auto node = tree_queue.front();
            ans.push_back(node->val);
            if (node->left) tree_queue.push(node->left);
            if (node->right) tree_queue.push(node->right);
            tree_queue.pop();
        }
        return ans;
    }
    //中序
    vector<int> inorderTraversalRecursion()
    {
        vector<int> ans;
        auto head = root_;
        dfs(head, ans, inorder);
        return ans;
    }

    //前序
    vector<int> preorderTraversalRecursion()
    {
        vector<int> ans;
        auto head = root_;
        dfs(head, ans, preorder);
        return ans;
    }

    //后序
    vector<int> postorderTraversalRecursion()
    {
        vector<int> ans;
        auto head = root_;
        dfs(head, ans, postorder);
        return ans;
    }

    //中序非递归
    vector<int> inorderTraversal(TraverseType type = inorderNoneRecursion)
    {
        vector<int> ans;
        auto cur_node = root_;
        stack<TreeNode*> tree_stack;
        while (cur_node || !tree_stack.empty()) {
            while (cur_node) {
                if (type == preorderNoneRecursion) ans.push_back(cur_node->val);
                tree_stack.push(cur_node);
                cur_node = cur_node->left;
            }
            cur_node = tree_stack.top();
            if (type == inorderNoneRecursion) ans.push_back(cur_node->val);
            cur_node = cur_node->right;
            tree_stack.pop();
        }
        return ans;
    }

    //前序非递归
    vector<int> preorderTraversal() { return inorderTraversal(preorderNoneRecursion); }

    //后序非递归
    vector<int> postorderTraversal()
    {
        vector<int> ans;
        auto cur_node = root_;
        decltype(cur_node) pre_node = nullptr;
        stack<TreeNode*> tree_stack;
        while (cur_node || !tree_stack.empty()) {
            while (cur_node) {
                tree_stack.push(cur_node);
                cur_node = cur_node->left;
            }

            cur_node = tree_stack.top();
            if (cur_node->right && cur_node->right != pre_node) {
                cur_node = cur_node->right;
            } else {
                ans.push_back(cur_node->val);
                pre_node = cur_node;
                cur_node = nullptr;
                tree_stack.pop();
            }
        }
        return ans;
    }

    TreeNode* getRoot() { return root_; }

   private:
    void dfs(TreeNode* node, vector<int>& ans_arr, TraverseType type)
    {
        if (node) {
            if (type == preorder) ans_arr.push_back(node->val);
            dfs(node->left, ans_arr, type);
            if (type == inorder) ans_arr.push_back(node->val);
            dfs(node->right, ans_arr, type);
            if (type == postorder) ans_arr.push_back(node->val);
        }
    }

   private:
    TreeNode* root_{nullptr};
};
}  // namespace tree_util

#endif