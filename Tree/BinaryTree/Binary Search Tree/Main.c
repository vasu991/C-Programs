#include "BinarySearchTree.c"

int main() {
    Tree* tree = createTree();
    insertBST(&tree->root, 10);
    insertBST(&tree->root, 56);
    insertBST(&tree->root, 1);
    insertBST(&tree->root, 68);
    insertBST(&tree->root, 7);
    printTree(tree->root, 0);
    int num = countNodes(tree->root);
    printf("Number of Nodes: %d\n", num);
    printTree(tree->root, 0);
//    inOrder(tree->root);
    return 0;
}