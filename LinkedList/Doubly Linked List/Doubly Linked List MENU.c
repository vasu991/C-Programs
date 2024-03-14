#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include "Doubly Linked List.c"

int main() {
    int choice;
    List* list = createList();
    printf("---------------DOUBLY LINKED LIST MENU---------------\n");
    do {
        printf("Enter your choice:\n");
        printf("1. For INSERTING an ELEMENT.\n");
        printf("2. To DISPLAY LINKED LIST Left to Right.\n");
        printf("3. To DISPLAY LINKED LIST Right to Left.\n");
        printf("4. EXIT.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int info;
                printf("Enter the VALUE of the ELEMENT: ");
                scanf("%d", &info);
                insert(list, info);
                break;
            }
            case 2: {
                displayLeftToRight(list);
                break;
            }
            case 3: {
                displayRightToLeft(list);
                break;
            }
            case 4: {
                printf("Exiting....\n");
                break;
            }
            default: {
                printf("Please enter a valid CHOICE...\n");
            }
        }
    } while (choice != 4);
    return 0;
}
#pragma clang diagnostic pop