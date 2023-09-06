/*
 @filename   50.cpp
 @author     caonan
 @date       2022-04-15 09:10:29
 @reference
 @url
 @brief  给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
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
using namespace tree_util;
using namespace std;

class Solution
{
   public:
    int pathSum(TreeNode* root, int targetSum)
    {
        unordered_map<int, int> path_count{{0, 1}};
        return dfs(root, path_count, targetSum, 0);
    }

   private:
    int dfs(TreeNode* head, unordered_map<int, int>& path_count,const int target, int sum)
    {
        if (!head) return 0;
        sum += head->val;
        
        int count = 0;
        if (path_count.find(sum - target) != path_count.end()) {
            count = path_count[sum - target];
        }
        path_count[sum]++;  //这个增加技术也很微妙，一定要在判断之后，这样能达到path_count存储的都是pre的效果，否则当target=0时，子数组和数组本身是重合的
        count += dfs(head->left, path_count, target, sum);
        count += dfs(head->right, path_count, target, sum);
        path_count[sum]--;  //多加的在函数结束要减回去，因为这是共享变量
        return count;
    }
};

int main() { return 0; }
