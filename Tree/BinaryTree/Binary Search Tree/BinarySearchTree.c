#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsizeof-array-argument"
#pragma clang diagnostic ignored "-Wsizeof-pointer-div"
#pragma ide diagnostic ignored "bugprone-sizeof-expression"
#pragma ide diagnostic ignored "misc-no-recursion"

#include<stdlib.h>
#include<stdio.h>
#define COUNT 8

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
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}
void insertBST(Node** root, int key) {
    if (*root == NULL) {
        *root = createNode(key);
        return;
    }
    if (key < (*root)->info) {
        insertBST(&((*root)->left), key);
    }
    else if (key > (*root)->info) {
        insertBST(&((*root)->right), key);
    }
}

int findMinimum(Node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return -1; // Or handle the empty tree case as needed
    }

    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->info;
}

int countNodes(Node* root){
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countNodesOnRight(Node* root) {
    if (root == NULL || root->right == NULL) {
        return 0;
    }
    return countNodes(root->right);
}

int countNodesWithBothChildren(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;
    if (root->left != NULL && root->right != NULL) {
        count = 1;
    }

    return count + countNodesWithBothChildren(root->left)
    + countNodesWithBothChildren(root->right);
}
void print2DUtil(Node* root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->info);

    print2DUtil(root->left, space);
}
void print2D(Node* root)
{
    print2DUtil(root, 0);
}

int countLeafNodes(Node* root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right==NULL)
        return 1;
    else
        return countLeafNodes(root->left)+
               countLeafNodes(root->right);
}

int countLeftChildNodes(Node* root) {
    if(root == NULL)
        return 0;
    if(root->left != NULL && root->right == NULL)
        return 1;
    else
        return countLeftChildNodes(root->left)+
               countLeftChildNodes(root->right);
}

void rangeSumBST(Node* root, int low, int high, int* sum) {
    if(root == NULL) {
        return;
    }

    rangeSumBST(root->left, low, high, sum);

    if (root->left->info >= low && root->right->info <= high) {
        *sum += root->info;
    }

    rangeSumBST(root->right, low, high, sum);
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