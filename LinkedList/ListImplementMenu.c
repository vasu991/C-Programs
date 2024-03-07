#include <stdio.h>
#include "ListImplement.c"



int main() {
    Node *left = NULL, *right = NULL;
    int n;

    do {
        printf("MENU\n");
        printf("----------------------------------\n");
        printf("1. For adding data.\n");
        printf("2. For displaying all the nodes.\n");
        printf("3. EXIT.\n");
        scanf("%d", &n);
        switch (n) {
            case 1: {
                int val;
                printf("enter the value of the node:\n");
                scanf("%d", &val);
                append(&left, &right, val);
            } break;
            case 2: {
                printList(left);
            } break;
            case 3: break;

            default: {
                printf("Wrong input!\n");
            }
        }

    } while(n != 3);

    return 0;
}