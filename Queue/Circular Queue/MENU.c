#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include "Circular Queue Implement.c"


int main() {
    int choice;
    Queue* q = createQueue();
    printf("##########Circular Queue MENU##########\n");
    do {
        printf("----------------------------------------\n");
        printf("Enter your choice.\n");
        printf("1. For ADDING an element.\n");
        printf("2. For SERVING the element.\n3. To DISPLAY Queue.\n");
        printf("4. EXIT\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int info;
                printf("Enter the value of the element:");
                scanf("%d", &info);
                insert(q, info);
                break;
            }
            case 2: {
                if(isEmpty(q)) {
                    printf("Queue is EMPTY.\n");
                    break;
                }
                int info = serve(q);
                printf("%d is SERVED.\n", info);
                break;
            }
            case 3: {
                if(isEmpty(q)) {
                    printf("Queue is EMPTY.\n");
                    break;
                }
                printQueue(q);
                break;
            }
            case 4: {
                printf("Exiting....\n");
                break;
            }
            default: {
                printf("Please enter a valid choice.\n");
            }
        }

    } while(choice != 4);

    return 0;
}

#pragma clang diagnostic pop