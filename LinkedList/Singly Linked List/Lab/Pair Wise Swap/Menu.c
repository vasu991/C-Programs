#include "Pair Wise Swap.c"

int main() {
    List* list = createList();
    int choice;
    do {
        printf("MENU\n");
        printf("----------------------------------\n");
        printf("1. For adding data.\n");
        printf("2. For displaying all the nodes.\n");
        printf("3. For swapping nodes pairwise.\n");
        printf("4. EXIT.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int val;
                printf("Enter the value of the node:");
                scanf("%d", &val);
                append(&list->start, &list->end, val);
            } break;
            case 2: {
                printList(list->start);
            } break;
            case 3: {
                pairWiseSwap(list->start);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Wrong input!\n");
            }
        }

    } while(choice != 4);
    return 0;
}