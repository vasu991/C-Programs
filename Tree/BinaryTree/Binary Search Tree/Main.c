#include "BinarySearchTree.c"

int main() {
    Tree* tree = createTree();
    insertBST(&tree->root, 70);
    insertBST(&tree->root, 100);
    insertBST(&tree->root, 56);
    insertBST(&tree->root, 1);
    insertBST(&tree->root, 68);
    insertBST(&tree->root, 7);
    insertBST(&tree->root, 121);
    insertBST(&tree->root, 6);
    print2D(tree->root);
    printf("Number of Nodes: %d\n", countNodes(tree->root));
    printf("Number of Leaf Nodes: %d\n", countLeafNodes(tree->root));
    printf("Number of with only Left Child: %d\n", countLeftChildNodes(tree->root));
    return 0;
}