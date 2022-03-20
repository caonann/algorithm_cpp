/*************************************************************************
	> File Name: 7.rebuild_tree.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月11日 星期六 18时13分35秒
 ************************************************************************/
//https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTreeIndex(preorder,0,preorder.size()-1, inorder,0,inorder.size()-1);
    }

	TreeNode* buildTreeIndex(vector<int>& preorder, int prestart,int preend,vector<int>& inorder,int instart,int inend)
	{
        if(prestart >= preorder.size() || instart >= inorder.size() || prestart > preend || instart >inend ) return nullptr;
		if(prestart >=preend || instart>=inend ) return new TreeNode(preorder[prestart]);
		TreeNode* root = new TreeNode(preorder[prestart]);
		int count = 0;
		for(int i=instart;i<=inend;i++)
		{
			if(preorder[prestart] == inorder[i]) break;
            count++;
		}
		int spilt_index = instart+count;
		root->left = buildTreeIndex(preorder,prestart+1,prestart+count,inorder,instart,spilt_index-1);
		root->right = buildTreeIndex(preorder,prestart+count+1,preend,inorder,spilt_index+1,inend);
		return root;
	}
};

class TreePrinter
{
public:
    void show(TreeNode *node){
        auto ret = printTree(node);
        for (auto line : ret)
        {
            for (auto i : line)
            {
                cout << i << " ";
            }

            cout << endl;
        }
    }
private:
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


void test(vector<int> preorder,vector<int> inorder)
{
    Solution s;
	TreeNode* root = s.buildTree(preorder,inorder);
	TreePrinter t;
	t.show(root);
}
int main()
{
	test({1,2,4,8,5,3,6,7},{8,4,2,5,1,6,3,7});
    test({3,9,20,15,7},{9,3,15,20,7});
    return 0;
}

