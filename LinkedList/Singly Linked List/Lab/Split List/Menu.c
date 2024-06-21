#include <stdio.h>
#include "Split List.c"

int main() {
    List* P = createList();
    List* Q = createList();
    List* R = createList();
    int choice;

    do {
        printf("MENU\n");
        printf("----------------------------------\n");
        printf("1. For adding data.\n");
        printf("2. For displaying all the nodes.\n");
        printf("3. For splitting P.\n");
        printf("4. EXIT.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int val;
                printf("Enter the value of the node:");
                scanf("%d", &val);
                appendNode(&P->start, val);
                break;
            }
            case 2: {
                printList(P->start);
                break;
            }
            case 3: {
                if(P->start == NULL) {
                    printf("List P is empty..\n");
                    break;

                }
                split(P->start, &Q->start, &R->start);
                printf("List Q:\n");
                printList(Q->start);
                printf("List R:\n");
                printList(R->start);
                Q->start = NULL;
                R->start = NULL;
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Wrong Input..\n");
            }
        }
    } while(choice != 4);
    return 0;
}