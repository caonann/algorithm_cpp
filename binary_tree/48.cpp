/*
 @filename   48.cpp
 @author     caonan
 @date       2022-04-14 12:16:37
 @reference 剑指offer专项
 @url   https://leetcode-cn.com/problems/h54YBf/
 @brief
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
反序列化算法执行逻辑，只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
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
using namespace std;
using namespace tree_util;

// Definition for a binary tree node.

class Codec
{
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        std::string s;
        dfs(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if (data[0] == '#') return nullptr;
        string num;
        stack<TreeNode*> tree_stack;
        TreeNode* root = nullptr;
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == '#') {
                if (i + 1 < data.length() && data[i + 1] == '#') {
                    tree_stack.pop();
                    ++i;
                } else if (tree_stack.top()->left) {
                    tree_stack.pop();
                }
            } else if (data[i] == ',') {
                int inum = stoi(num);
                num.clear();
                TreeNode* node = new TreeNode(inum);
                while (!tree_stack.empty()) {
                    auto node_top = tree_stack.top();
                    if (node_top->left && node_top->right) {
                        tree_stack.pop();
                        continue;
                    }
                    if (!node_top->left)
                        node_top->left = node;
                    else if (!node_top->right)
                        node_top->right = node;
                    break;
                }
                if (!root) root = node;
                tree_stack.push(node);
            } else {
                num += data[i];
            }
        }

        while (!tree_stack.empty()) {
            root = tree_stack.top();
            tree_stack.pop();
        }
        return root;
    }

   private:
    void dfs(TreeNode* head, std::string& serialize_val)
    {
        if (!head) {
            serialize_val += "#";
            return;
        }
        int val = head->val;
        serialize_val += std::to_string(val) + ",";
        dfs(head->left, serialize_val);
        dfs(head->right, serialize_val);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main()
{
    Traversal t(1);
    auto root = t.getRoot();
    Codec c;
    string s = c.serialize(root);
    cout << "serialize " << s << endl;
    auto node = c.deserialize(s);
    t.show_graph_current_tree(node);
    return 0;
}
