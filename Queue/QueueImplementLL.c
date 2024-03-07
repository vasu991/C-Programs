#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

bool isEmpty(Node* front) {
    if(front == NULL) {
        return true;
    }
    return false;
}

void insert(Node** front, Node** rear, int info) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        printf("Memory Overflow.\n");
        return;
    }
    node->info = info;
    if(*front == NULL && *rear == NULL) {// first element
        *front = node;
        *rear = node;
        (*rear)->next = NULL;
        return;
    }
    (*rear)->next = node;
    *rear = node;
    (*rear)->next = NULL;
}

int serve(Node** front, Node** rear) {
    Node* temp = *front;
    int info = temp->info;
    if(*front == *rear) {// last element
        free(temp);
        *front = NULL;
        *rear = NULL;
        return info;
    }
    *front = (*front)->next;
    free(temp);
    return info;
}

void printQueue(Node* front) {
    while(front != NULL) {
        printf("%d <-- ", front->info);
        front = front->next;
    }
    printf("END\n");
}