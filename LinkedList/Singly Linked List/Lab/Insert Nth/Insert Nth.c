#include<stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct LinkedList {
    struct Node* head;
} List;

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->head = NULL;
    return list;
}

int size(List* ls) {
    int s = 0;
    Node* temp = ls->head;
    while(temp != NULL) {
        s++;
        temp = temp->next;
    }
    return s;
}

void insertNth(List* ls, int data, int position) {
    if(position < 1) {
        printf("Invalid Position..Can not assign negative or zero position..\n");
        return;
    }
    if(ls->head == NULL) {
        if(position != 1) {
            printf("Invalid Position..\n");
            return;
        }
        else {
            Node* node = createNode(data);
            ls->head = node;
            return;
        }
    }
    if(size(ls) + 1 < position){
        printf("Invalid Position..Cannot insert at position grater than size..\n");
        return;
    }
    Node* node = createNode(data);
    if(position == 1) {
        node->next = ls->head;
        ls->head = node;
        return;
    }
    Node* curr = ls->head->next;
    Node* prev = ls->head;
    for(int i = 1; i < position - 1; i++) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = node;
    node->next = curr;
}