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

void insertAscending(List* list, int info) {
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
        if(info < list->left->info) {
            node->next = list->left;
            list->left->prev = node;
            list->left = node;
        }
        else if(info > list->right->info) {
            node->prev = list->right;
            list->right->next = node;
            list->right = node;
        }
        else {
            Node* temp = list->left;
            while(temp->info < info) {
                temp = temp->next;
            }
            node->prev = temp;
            node->next = temp->next;
            (temp->next)->prev = node;
            temp->next = node;
        }
    }
}

int delete(List* list, int key) {
    if(list->left == NULL) {
        printf("List is empty!!\n");
        return -1;
    }

    Node* temp = list->left;

    while((temp != NULL) && (key != temp->info))
        temp = temp->next;
    if(temp == NULL) {
        printf("Key not found!\n");
        return -1;
    }

    int info;

    if((temp->prev == NULL) && (temp->next == NULL)) {
        info = temp->info;
        free(temp);
        list->left = NULL;
        list->right = NULL;
        return info;
    }
    if(temp == list->left) {
        info = temp->info;
        list->left = list->left->next;
        list->left->prev = NULL;
        free(temp);
        return info;
    }
    if(temp->next == NULL) {
        info = temp->info;
        list->right = list->right->prev;
        list->right->next = NULL;
        free(temp);
        return info;
    }
    info = temp->info;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return info;
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