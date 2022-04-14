#include "traverse.h"
using namespace tree_util;
void uinttest_print(int node_count)
{
    Traversal tree_root(node_count);
    tree_root.show_graph_current_tree();
    for (int type = Traversal::inorder; type <= Traversal::bfs; type++) {
        tree_root.show_val_order(static_cast<Traversal::TraverseType>(type));
    }
}

void uinttest(int node_count)
{
    Traversal tree_root(node_count);
    assert(tree_root.inorderTraversalRecursion() == tree_root.inorderTraversal());
    assert(tree_root.preorderTraversalRecursion() == tree_root.preorderTraversal());
    assert(tree_root.postorderTraversalRecursion() == tree_root.postorderTraversal());
}
int main()
{
    for (int i = 0; i < 1000; i++) uinttest(i);
    uinttest_print(10);
    return 0;
}