#include "common_define.h"
//https://www.nowcoder.com/questionTerminal/8b3b95850edb4115918ecebdf1b4d222

//平衡二叉树定义
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr) return true;
        int height = isAvlTree(pRoot,0);
        if(height<0)
        {
            return false;
        }
        else{
            return true;
        }
    }

    int isAvlTree(TreeNode* pNode,int height)
    {
        if(pNode == nullptr) return height;
        int left_height = isAvlTree(pNode->left,height+1);
        int right_height = isAvlTree(pNode->right,height+1);
        if(left_height<0||right_height<0)
        {
            return -1;
        }

        if(std::abs(left_height-right_height)<=1)
        {
            return std::max(left_height,right_height);
        }
        else
        {
            return -1;
        }
    }
};

TEST(NiuKeAdvanced, IsBalancedSolution)
{
    Solution s;
    std::vector<int> tree_arr{1,2,3,4,5,6,7,8,9,10};
    TreeNode* tree = comm::createTree(tree_arr);
    bool ret = s.IsBalanced_Solution(tree);
    EXPECT_TRUE(ret == true);
}