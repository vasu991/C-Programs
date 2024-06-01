#include "BinarySearchTree.c"

int main() {
    Tree* tree = createTree();
    insertBST(&tree->root, 70);
    insertBST(&tree->root, 30);
    insertBST(&tree->root, 90);
    print2D(tree->root);
    int sum;
    int* ptrSum = &sum;
    rangeSumBST(tree->root, 10, 90, ptrSum);
    printf("Range Sum: %d", sum);
    return 0;
}