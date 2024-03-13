
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct Queue {
    int front, rear, max, tq;
    int arr[MAX_SIZE];
} Queue;

Queue* createQueue(int max, int tq) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->max = max;
    q->front = -1;
    q->rear = -1;
    q->tq = tq;
    return q;
}

bool isFull(Queue* q) {
    if(q->front == 0 && q->rear == (q->max) - 1) {
        return true;
    }
    if(q->front == q->rear + 1) {
        return true;
    }
    return false;
}
bool isEmpty(Queue* q) {
    if(q->front == -1 && q->rear == -1) {
        return true;
    }
    return false;
}

void insert(Queue* q, int bt) {
    if(q->front == -1 && q->rear == -1) {// first element
        q->front++;
        q->rear++;
        q->arr[q->front] = bt;
        return;
    }
    q->rear = (q->rear + 1);
    q->arr[q->rear] = bt;
}

int serve(Queue* q) {
    int bt;
    if(q->front == q->rear && q->front != -1) {// last element
        bt = q->arr[q->front];
        q->arr[q->front] = 0;
        q->rear = -1;
        q->front = -1;
        return bt;
    }
    bt = q->arr[q->front];
    q->arr[q->front] = 0;
    q->front = (q->front + 1);
    return bt;
}

void printQueue(Queue* q) {
    if(q->front == -1) {
        printf("Queue is EMPTY.\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++) {
        printf("%d <-- ", q->arr[i]);
    }
    printf("END");
    printf("\n");
}
