/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   1.2_TreePrinter.cpp
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/

#include "common_define.h"
// https://www.nowcoder.com/study/vod/1/1/2

// 重点是标记下一层最右节点和当前要换行节点

class TreePrinter
{
public:
    vector<vector<int> > printTree(TreeNode *root)
    {
        // write code here
        if (!root) return vector<vector<int>> {};
        TreeNode *last = root;
        TreeNode *nlast = last;

        vector<vector<int>> res;
        vector<int> line;

        queue<TreeNode *> binary_que;

        binary_que.push(root);

        while (!binary_que.empty())
        {
            TreeNode *node = binary_que.front();
            line.push_back(node->val);

            if (node->left)
            {
                nlast = node->left;
                binary_que.push(node->left);
            }

            if (node->right)
            {
                nlast = node->right;
                binary_que.push(node->right);
            }

            if (node == last)
            {
                last = nlast;
                res.push_back(line);
                line.clear();
            }

            binary_que.pop();
        }

        return res;
    }
};


int main()
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<unsigned> u(0, 100);
    vector<int> tree_list;

    for (int i = 0; i < 100; i++)
    {
        tree_list.push_back(u(e));
    }

    TreeNode *root = comm::createTree(tree_list);
    TreePrinter t;
    vector<vector<int>> ret = t.printTree(root);

    for (auto line : ret)
    {
        for (auto i : line)
        {
            cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}

