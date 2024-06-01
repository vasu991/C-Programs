#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

typedef struct Node {
    struct Node* prev;
    int info;
    struct Node* next;
} Node;

typedef struct List {
    Node* start;
    Node* end;
} List;

Node* createNode() {
    Node* node = (Node*) malloc(sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    return node;
}

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->start = NULL;
    list->end = NULL;
    return list;
}
bool isEmpty(List* list) {
    if(list->start == NULL) {
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
        list->start = node;
        list->end = node;
    }
    else {
        list->end->next = node;
        node->prev = list->end;
        list->end = node;
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
        list->start = node;
        list->end = node;
    }
    else {
        if(info < list->start->info) {
            node->next = list->start;
            list->start->prev = node;
            list->start = node;
        }
        else if(info > list->end->info) {
            node->prev = list->end;
            list->end->next = node;
            list->end = node;
        }
        else {
            Node* temp = list->start;
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
    if(list->start == NULL) {
        printf("List is empty!!\n");
        return -1;
    }

    Node* temp = list->start;

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
        list->start = NULL;
        list->end = NULL;
        return info;
    }
    if(temp == list->start) {
        info = temp->info;
        list->start = list->start->next;
        list->start->prev = NULL;
        free(temp);
        return info;
    }
    if(temp->next == NULL) {
        info = temp->info;
        list->end = list->end->prev;
        list->end->next = NULL;
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
    Node* temp = list->end;
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
    Node* temp = list->start;
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