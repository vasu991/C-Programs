#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

typedef struct Node {
    struct Node* prev;
    int info;
    struct Node* next;
} Node;

typedef struct List {
    Node* left;
    Node* right;
} List;

Node* createNode() {
    Node* node = (Node*) malloc(sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    return node;
}

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->left = NULL;
    list->right = NULL;
    return list;
}
bool isEmpty(List* list) {
    if(list->left == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void insert(List* list, int info) {
    Node* node = createNode();
    if(node == NULL) {
        printf("Memory OVERFLOW.\n");
        return;
    }
    node->info = info;
    if(isEmpty(list)) {
        list->left = node;
        list->right = node;
    }
    else {
        list->right->next = node;
        node->prev = list->right;
        list->right = node;
    }
}

void displayRightToLeft(List* list) {
    Node* temp = list->right;
    if(isEmpty(list)) {
        printf("List is EMPTY.\n");
    }
    else {
        printf("END");
        while(temp != NULL) {
            printf(" <--> %d", temp->info);
            temp = temp->prev;
        }
        printf(" <--> START");
        printf("\n");
    }

}

void displayLeftToRight(List* list) {
    Node* temp = list->left;
    if(isEmpty(list)) {
        printf("List is EMPTY.\n");
    }
    else {
        printf("START <--> ");
        while(temp != NULL) {
            printf("%d <--> ", temp->info);
            temp = temp->next;
        }
        printf("END\n");
    }

}