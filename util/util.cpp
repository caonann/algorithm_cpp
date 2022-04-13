#include "util.h"
using namespace std;

namespace comm
{
TreeNode *createTree(vector<int> &arr)
{
    if (arr.empty()) return nullptr;
    vector<TreeNode *> treenode_arr;
    for (auto &v : arr) treenode_arr.emplace_back(new TreeNode(v));
    int len = static_cast<int>(arr.size());
    for (int i = 0; i < len / 2 - 1; i++) {
        int left_idx = 2 * i + 1;
        int right_idx = 2 * i + 2;
        TreeNode *node = treenode_arr[i];
        node->left = treenode_arr[left_idx];
        if (right_idx < len) node->right = treenode_arr[right_idx];
    }
    return treenode_arr[0];
}

}  // namespace comm

int RandomUtils::getInt(int start, int end)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<int> u(start, end);
    return u(e);
}

double RandomUtils::getDouble(double start, double end)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_real_distribution<double> u(start, end);
    return u(e);
}