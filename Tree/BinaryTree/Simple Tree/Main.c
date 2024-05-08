#include "SimpleTree.c"

int main() {
    Tree* tree = createTree();
    populateTree(tree);
    preOrder(tree->root);
//    inOrder(tree->root);
//    postOrder(tree->root);
    return 0;
}