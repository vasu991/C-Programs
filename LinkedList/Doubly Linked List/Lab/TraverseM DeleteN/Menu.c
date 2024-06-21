#include "TraverseMdeleteN.c"

int main() {
    int choice;
    List* list = createList();
    do {
        printf("Enter your choice:\n");
        printf("1. For INSERTING an ELEMENT.\n");
        printf("2. To DISPLAY LINKED LIST Left to Right.\n");
        printf("3. To Traverse M nodes and delete N nodes.\n");
        printf("4. EXIT.\n");
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
                displayLeftToRight(list);
                break;
            }
            case 3: {
                int N, M;
                printf("Enter the value of N:\n");
                scanf("%d", &N);
                printf("Enter the value of M:\n");
                scanf("%d", &M);
                traverseMdeleteN(list, M , N);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Please enter a valid CHOICE...\n");
            }
        }
    } while (choice != 4);
    return 0;
}