#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include<stdlib.h>
#include "QueueImplementArray.c"

int main() {
    int choice;
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    printf("*********Queue operations using array*********");

    printf("\n----------------------------------------------\n");

    do {
        printf("Chose one from the below options...\n");
        printf("\n1.Insert\n2.Serve\n3.Show Queue Elements\n4.Exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                if(isFull(q)) {
                    printf("Queue is full.\n");
                    break;
                }
                int info;
                printf("Enter the value of the element:\n");
                scanf("%d", &info);
                insert(q, info);
                break;
            }
            case 2:
            {
                if(isEmpty(q)) {
                    printf("Queue is Empty.\n");
                    break;
                }
                int info = serve(q);
                printf("%d is served.\n", info);
                break;
            }
            case 3:
            {
                if(isEmpty(q)) {
                    printf("Queue is Empty.\n");
                    break;
                }
                printQueue(q);
                break;
            }
            case 4:
            {
                printf("Exiting....");
                break;
            }
            default:
            {
                printf("Please Enter valid choice\n");
            }
        }
    } while(choice != 4);

    return 0;
}

#pragma clang diagnostic pop