#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsizeof-array-argument"
#pragma clang diagnostic ignored "-Wsizeof-pointer-div"
#pragma ide diagnostic ignored "bugprone-sizeof-expression"
#pragma ide diagnostic ignored "misc-no-recursion"

#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    int info;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Node* createNode(int info) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->info = info;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));\
    tree->root = NULL;
    return tree;
}
void insertBST(Node** root, int key) {
    if(*root == NULL) {
        *root = createNode(key);
        (*root)->info = key;
        return;
    }

    if((*root)->info < key) {
        insertBST(&((*root)->right), key);
    } else {
        insertBST(&((*root)->left), key);
    }
}

int countNodes(Node* root){
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void printTree(Node* root, int level) {
    if (root == NULL)
        return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("   ");
    printf("%d\n", root->info);
    printTree(root->left, level + 1);
}


void preOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    printf("%d ", node->info);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d ", node->info);
    inOrder(node->right);
}

void postOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->info);
}


#pragma clang diagnostic pop