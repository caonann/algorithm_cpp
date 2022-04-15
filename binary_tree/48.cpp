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

    //来一个数字或#优先挂parent左节点，左节点不让挂就挂右节点，左右都挂则pop
    //不能用left,right指针因为即使通过#判断节点为空了，再去用来判断还是无法区分是否可以挂节点
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        TreeNode* root = nullptr;
        if (data[0] == '#') return root;
        string num;
        struct WrapTreeNode {
            WrapTreeNode(int val) : node_ptr(new TreeNode(val)) {}
            TreeNode* node_ptr = nullptr;
            bool left_available = true;
            bool right_available = true;
        };
        stack<WrapTreeNode> tree_stack;
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == '#') {
                auto& parent = tree_stack.top();
                if (parent.left_available) {
                    parent.left_available = false;
                } else {
                    tree_stack.pop();
                }
            } else if (data[i] == ',') {
                int inum = stoi(num);
                num.clear();
                WrapTreeNode node(inum);
                if (tree_stack.empty()) root = node.node_ptr;
                while (!tree_stack.empty()) {
                    auto& parent = tree_stack.top();
                    if (parent.left_available) {
                        parent.left_available = false;
                        parent.node_ptr->left = node.node_ptr;
                        break;
                    } else if (parent.right_available) {
                        parent.node_ptr->right = node.node_ptr;
                        tree_stack.pop();
                        break;
                    } else {
                        tree_stack.pop();
                    }
                }
                tree_stack.emplace(node);
            } else {
                num += data[i];
            }
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

//用前序和中序来构建二叉树
class Codec1 : public Codec
{
    string serialize(TreeNode* root) { return ""; }
    TreeNode* deserialize(string data) { return nullptr; }
};

//采用递归方法，代码少的多..
class Codec2 : public Codec
{
   public:
    string serialize(TreeNode* root)
    {
        if (!root) return "#";
        string s;
        s += to_string(root->val) + "," + serialize(root->left);
        s += serialize(root->right);
        return s;
    }
    TreeNode* deserialize(string data)
    {
        int index = 0;
        return dfs(data, index);
    }

   private:
    TreeNode* dfs(string& s, int& i)
    {
        if (s[i] == '#') {
            ++i;
            return nullptr;
        }
        int len = i;
        while (s[len++] != ',');
        int inum = stoi(s.substr(i, len - i - 1));
        i = len;
        TreeNode* root = new TreeNode(inum);
        root->left = dfs(s, i);
        root->right = dfs(s, i);
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main()
{
    Traversal t(10);
    auto root = t.getRoot();
    Codec c1;
    Codec2 c;
    assert(c1.serialize(root) == c.serialize(root));
    string s = c.serialize(root);
    cout << "serialize " << s << endl;
    auto node = c.deserialize(s);
    t.show_graph_current_tree(node);
    return 0;
}
