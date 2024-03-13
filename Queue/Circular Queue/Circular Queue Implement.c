#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue* q) {
    if(q->front == NULL) {
        return true;
    }
    return false;
}

void insert(Queue* q, int info) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        printf("Memory Overflow.\n");
        return;
    }
    node->info = info;
    if (isEmpty(q)) {
        q->front = q->rear = node;
        q->rear->next = q->front;
    } else {
        q->rear->next = node;
        q->rear = node;
        q->rear->next = q->front;
    }
}

int serve(Queue* q) {
    Node* temp = q->front;
    int info = temp->info;
    if(q->front == q->rear) {// last process
        free(temp);
        q->front = NULL;
        q->rear = NULL;
        return info;
    }
    q->front = q->front->next;
    q->rear->next = q->front;
    free(temp);
    return info;
}

//void printFrontRear(Queue* q) {
//    printf("Front: %d\n", q->front->info);
//    printf("Rear: %d\n", q->rear->info);
//    printf("Rear Next: %d\n", q->rear->next->info);
//}

void printQueue(Queue* q) {
    Node* temp = q->rear;
     do {// rear --> front -->...--> rear-1
        printf("%d --> ", temp->info);
        temp = temp->next;
    } while(temp != q->rear);
    printf("END\n");
}
