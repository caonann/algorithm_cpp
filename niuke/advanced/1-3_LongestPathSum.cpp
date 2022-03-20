/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   1-3_LongestPathSum.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/
//
// Created by cn on 2019/6/4.
//

/*
 给定一棵二叉树的头节点head，和一个整数sum，二叉树每个节点上都 有数字，我们规定路径必须是从上往下的，求二叉树上累加和为sum的最长路径长度
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{

    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *build_tree_node(std::vector<int> &arr)
{
    if (arr.empty())
    {
        return nullptr;
    }

    // TreeNode *root = new TreeNode(0);

    for (int i = 0; i < arr.size(); i++)
    {
        arr[2 * i + 1] = 0;
    }

    return nullptr;
}

class CLongestPathSum
{
public:
    int LongestPathSum(TreeNode *root, int sum)
    {
        m_input_sum = sum;

        if (!root)
        {
            return -1;
        }

        FrontTraverse(root);
        return m_longest_path;
    }

    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->value == sum && root->left == nullptr && root->right == nullptr)
        {
            return true;
        }

        return hasPathSum(root->left, sum - root->value) || hasPathSum(root->right, sum - root->value);
    }

    bool getret()
    {
        return isget;
    }

private:
    void FrontTraverse(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        int value = node->value;

        if (m_stack_sum.empty())
        {
            m_stack_sum.push(value);
        }
        else
        {
            int sum = value + m_stack_sum.top();

            if (sum == m_input_sum)
            {
                isget = true;
                m_longest_path = m_longest_path > m_stack_sum.size() ? m_longest_path : m_stack_sum.size();
            }

            m_stack_sum.push(sum);
        }

        if (node->left)
        {
            FrontTraverse(node->left);

            if (!m_stack_sum.empty())
            {
                m_stack_sum.pop();
            }
        }

        if (node->right)
        {
            FrontTraverse(node->right);

            if (!m_stack_sum.empty())
            {
                m_stack_sum.pop();
            }
        }
    }

    int m_input_sum = 0;
    int m_longest_path = 0;
    bool isget = false;
    std::stack<int> m_stack_sum;
};



int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    CLongestPathSum obj;
    int longest_path = obj.LongestPathSum(root, 22);
    cout << "longset path " << longest_path << endl;
    cout << "is true " << obj.getret() << endl;
    return 0;
}