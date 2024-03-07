#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

#include "QueueImplementLL.c"

int main() {
    int choice;
    Node* front = NULL;
    Node* rear = NULL;
    printf("*********Queue operations using Linked List*********");

    printf("\n----------------------------------------------\n");

    do {
        printf("Chose one from the below options...\n");
        printf("\n1.Insert\n2.Serve\n3.Show Queue Elements\n4.Exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1: {
                int info;
                printf("Enter the element you want to enter:\n");
                scanf("%d", &info);
                insert(&front, &rear, info);
                break;
            }
            case 2: {
                if(isEmpty(front)) {
                    printf("Queue is empty.\n");
                    break;
                }
                int info = serve(&front, &rear);
                printf("%d is served.\n", info);
                break;
            }
            case 3: {
                if(isEmpty(front)) {
                    printf("Queue is empty.\n");
                    break;
                }
                printQueue(front);
                break;
            }
            case 4: {
                printf("Exiting....\n");
                break;
            }
            default: {
                printf("Please Enter valid choice\n");
            }
        }
    } while(choice != 4);

    return 0;
}

#pragma clang diagnostic pop