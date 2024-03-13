#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct Queue {
    int front, rear;
    int arr[MAX];
} Queue;

bool isFull(Queue* q) {
    if(q->front == 0 && q->rear == MAX-1) {
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

void insert(Queue* q, int info) {
    if(q->front == -1 && q->rear == -1) {// first element
        q->front++;
        q->rear++;
        q->arr[q->front] = info;
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = info;
}

int serve(Queue* q) {
    int info;
    if(q->front == q->rear && q->front != -1) {// last element
        info = q->arr[q->front];
        q->rear = -1;
        q->front = -1;
        return info;
    }
    info = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    return info;
}

void printQueue(Queue* q) {
    for(int i = q->front; i <= q->rear; i++) {
        printf("%d <-- ", q->arr[i]);
    }
    printf("END");
    printf("\n");
}



