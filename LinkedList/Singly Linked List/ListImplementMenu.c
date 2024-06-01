#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include "ListImplement.c"



int main() {
    Node *start = NULL, *end = NULL;
    int n;

    do {
        printf("MENU\n");
        printf("----------------------------------\n");
        printf("1. For adding data.\n");
        printf("2. For displaying all the nodes.\n");
        printf("3. For deleting a node with a particular value.\n");
        printf("4. For inserting in ascending order.\n");
        printf("5. Pair Wise swap nodes.\n");
        printf("6. EXIT.\n");
        scanf("%d", &n);
        switch (n) {
            case 1: {
                int val;
                printf("Enter the value of the node:");
                scanf("%d", &val);
                append(&start, &end, val);
            } break;
            case 2: {
                printList(start);
            } break;
            case 3: {
                int key;
                printf("Enter the value of the NODE which is to be DELETED:");
                scanf("%d", &key);
                int deleted = deleteByValue(&start, &end, key);
                if(deleted != -1) {
                    printf("%d is DELETED.\n", deleted);
                }
                break;
            }
            case 4: {
                int info;
                printf("Enter the value of the NODE:");
                scanf("%d", &info);
                insertAscending(&start, &end, info);
                break;
            }
            case 5: {
                pairWiseSwap(start);
            }
            case 6: {
                printf("Exiting....\n");
                break;
            }

            default: {
                printf("Wrong input!\n");
            }
        }

    } while(n != 6);
    return 0;
}
#pragma clang diagnostic pop