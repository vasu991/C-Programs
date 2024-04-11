#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#pragma ide diagnostic ignored "cert-err34-c"
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

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    return node;
}

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    return tree;
}

void populate(Node* node) {
    int left;
    printf("Enter number > 0 if you want to insert the LEFT of NODE %d:\n", node->info);
    printf("(If not then enter 0)\n");
    scanf("%d", &left);
    if(left) {
        Node* node1 = createNode();
        printf("Enter the value of the LEFT of NODE %d:\n", node->info);
        scanf("%d", &node1->info);
        node->left = node1;
        populate(node->left);
    }
    else {
        node->left = NULL;
    }
    int right;
    printf("Enter number > 0 if you want to insert the RIGHT of NODE %d:\n", node->info);
    printf("(If not then enter 0)\n");
    scanf("%d", &right);
    if(right) {
        Node* node2 = createNode();
        printf("Enter the value of the RIGHT of NODE %d:\n", node->info);
        scanf("%d", &node2->info);
        node->right = node2;
        populate(node->right);
    }
    else {
        node->right = NULL;
    }
}
void populateTree(Tree* tree) {
    Node* root = createNode();
    printf("Enter the value of the ROOT NODE:\n");
    scanf("%d", &root->info);
    tree->root = root;
    populate(tree->root);
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
    preOrder(node->left);
    printf("%d ", node->info);
    preOrder(node->right);
}

void postOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    preOrder(node->left);
    preOrder(node->right);
    printf("%d ", node->info);
}

#pragma clang diagnostic pop