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

int size(List* list) {
    Node* temp = list->start;
    int s = 0;
        while(temp != NULL) {
            s++;
            temp = temp->next;
        }
    return s;
}



    void traverseMdeleteN(List* list, int M, int N) {
        if(N == 0) {
            return;
        }
    if(M == 0 && N == size(list)) {
        list->start = NULL;
        list->end = NULL;
        return;
    }
    if(M == 0) {
        Node* temp = list->start;
        for(int i = 1; i <= N; i++) {
            temp = temp->next;
        }
        temp->prev = NULL;
        list->start = temp;
        return;
    }
    if(N + M > size(list)) {
        printf("Invalid N, M or both..\n");
        return;
    }
    Node* temp1 = list->start;
    for(int i = 1; i < M; i++) {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1;
    for (int i = 1; i <= N + 1; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2;
    if(temp2 != NULL) {
        temp2->prev = temp1;
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