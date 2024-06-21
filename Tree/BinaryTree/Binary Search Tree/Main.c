#include "BinarySearchTree.c"

int main() {
    Tree* tree = createTree();
    int choice;
     do {
         printf("---------MENU---------\n");
         printf("1. For adding node.\n");
         printf("2. For Displaying BST.\n");
         printf("3. Count nodes having left child only in the BST.\n");
         printf("4. Print node having smallest information in the binary search tree.\n");
         printf("5. Count total number of leaf nodes.\n");
         printf("6. Count nodes having both children in the binary search tree.\n");
         printf("7. Count total numbers of nodes from right hand side of root node.\n");
         printf("8. EXIT.\n");
         scanf("%d", &choice);
         switch (choice) {
             case 1: {
                 int value;
                 printf("Enter the value of the node:\n");
                 scanf("%d", &value);
                 insertBST(&tree->root, value);
             } break;
             case 2: {
                 print2D(tree->root);
             } break;
             case 3: {
                 printf("Left Child Nodes: %d\n", countLeftChildNodes(tree->root));
             } break;
             case 4: {
                 int min = findMinimum(tree->root);
                 if(min == -1) {
                     printf("Tree is empty!\n");
                     break;
                 }
                 printf("Minimum Value Node: %d\n", min);
             } break;
             case 5: {
                 printf("Leaf Nodes: %d\n", countLeafNodes(tree->root));
             } break;
             case 6: {
                 int countBothChilds = countNodesWithBothChildren(tree->root);
                 printf("Nodes with both left and right children: %d\n", countBothChilds);
             } break;
             case 7: {
                 int countRightNodes = countNodesOnRight(tree->root);
                 printf("Nodes to the right of root node: %d\n", countRightNodes);
             } break;
             case 8: {
                 printf("Exiting...\n");
             }
             default: {
                 printf("Wrong Input..\n");
             }
         }
     } while(choice != 5);
    return 0;
}