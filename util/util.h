/*************************************************************************
    > File Name: common_define.h
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sat 03 Aug 2019 03:26:23 AM UTC
 ************************************************************************/

#ifndef _COMMON_DEFINE_H
#define _COMMON_DEFINE_H
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define LOG(...)                                     \
    do {                                             \
        printf("%s line %d:\t", __func__, __LINE__); \
        printf(__VA_ARGS__);                         \
        printf("\n");                                \
    } while (0)

namespace comm
{

TreeNode *createTree(std::vector<int> &arr);
}  // namespace comm

class RandomUtils
{
   public:
    static int getInt(int start = 0, int end = INT_MAX);
    static double getDouble(double start = 0, double end = INT_MAX);
};
namespace
{

template <typename T>
void printItemList(T &itemlist)
{
    for (auto &v : itemlist) {
        std::cout << v << " ";
    }

    printf("\n");
}

}  // namespace

#endif