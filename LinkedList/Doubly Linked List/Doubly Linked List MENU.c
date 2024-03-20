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
        printf("2. For INSERTING in ASCENDING ORDER.\n");
        printf("3. To DISPLAY LINKED LIST Left to Right.\n");
        printf("4. To DISPLAY LINKED LIST Right to Left.\n");
        printf("5. To DELETE a NODE.\n");
        printf("6. EXIT.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int info;
                printf("Enter the VALUE of the ELEMENT:");
                scanf("%d", &info);
                insert(list, info);
                break;
            }

            case 2: {
                int info;
                printf("Enter the VALUE of the ELEMENT:");
                scanf("%d", &info);
                insertAscending(list, info);
                break;
            }
            case 3: {
                displayLeftToRight(list);
                break;
            }
            case 4: {
                displayRightToLeft(list);
                break;
            }
            case 5: {
                int key;
                int deleted;
                printf("ENTER the value of the NODE you want to DELETE:");
                scanf("%d", &key);
                deleted = delete(list, key);
                if(deleted == -1) {
                    printf("NODE is NOT DELETED.\n");
                }
                else {
                    printf("%d is DELETED.\n", deleted);
                }
                break;
            }
            case 6: {
                printf("Exiting....\n");
                break;
            }
            default: {
                printf("Please enter a valid CHOICE...\n");
            }
        }
    } while (choice != 6);
    return 0;
}
#pragma clang diagnostic pop