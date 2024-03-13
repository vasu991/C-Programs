#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include<stdio.h>
#include "ProcessingQueue.c"

void run(Queue* q) {
    q->arr[q->front] -= q->tq;
    if(q->arr[q->front] <= 0) {
        serve(q);
    }
}

void displayTable(Queue* q) {
    int time = 0;
    printf("------------COMPLETION TABLE------------\n");
    printf("%*c", 12, ' ');
    for (int i = q->front; i <= q->rear; i++) {
        printf("%c%d", 'P', i);
        printf("%*c", 6, ' ');
    }
    printf("\n");
    while(q->front != -1) {
        printf("Time:%*d",4,  time);
        for(int i = 0; i <= q->rear; i++) {
            if(q->arr[i] <= 0) {
                printf("%*c", 6, '-');
            }
            else {
                printf("%*d", 6, q->arr[i]);
            }
        }
        run(q);
        printf("\n");
        time += q->tq;
    }
}

int main() {
    int choice, max, tq;
    int process = 1;

    printf("MULTIPROCESSING MENU\n");
    printf("----------------------------------------------------\n");
    printf("Enter the size of the PROCESSING QUEUE:\n");
    scanf("%d", &max);
    printf("Enter the TIME QUANTUM for the CPU:\n");
    scanf("%d", &tq);
    Queue* q = createQueue(max, tq);
    printf("-------Enter the BURST TIME for the PROCESSES-------\n");
    do {
        printf("---------------PROCESSING QUEUE MENU----------------\n");
        printf("1. For ADDING a PROCESS\n2. EXIT\n");
        printf("Enter your CHOICE:\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                if(isFull(q)) {
                    printf("Queue is FULL\n");
                    choice = 0;
                    break;
                }
                int bt;
                printf("Enter the BURST TIME of PROCESS %d: ", process);
                scanf("%d", &bt);
                insert(q, bt);
                process++;
                break;
            }
            case 2: {
                printf("EXITING.......\n");
                break;
            }
            default: {
                printf("Please enter a valid input...\n");
            }
        }
    } while(choice != 2);
    displayTable(q);
    printQueue(q);
    return 0;
}
#pragma clang diagnostic pop