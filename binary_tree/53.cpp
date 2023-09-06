/*
 @filename   53.cpp
 @author     caonan
 @date       2022-04-18 15:46:54
 @reference
 @url
 @brief
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

class Solution
{
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        TreeNode* cur = root;
        TreeNode* ans = nullptr;
        while (cur) {
            if (cur->val > p->val) {
                ans = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return ans;
    }
};
int main() { return 0; }
