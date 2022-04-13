#include "util.h"
using namespace comm;
using namespace std;

int main()
{
    vector<int> tree_nodes;
    for (int i = 0; i < 100; i++) {
        auto double_sum = RandomUtils::getDouble();
        auto int_sum = RandomUtils::getInt();
        LOG("double_sum %lf,int_sum %d", double_sum, int_sum);
        tree_nodes.push_back(int_sum);
    }
    printItemList(tree_nodes);
    TreeNode* root = comm::createTree(tree_nodes);
    return 0;
}