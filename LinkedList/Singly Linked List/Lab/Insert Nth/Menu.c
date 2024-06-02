
#include "Insert Nth.c"

int main() {
    List* ls = createList();
    int choice;

    do {
        printf("MENU\n");
        printf("----------------------------------\n");
        printf("1. For adding node to Nth position.\n");
        printf("2. EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the value of the node:\n");
                int value;
                scanf("%d", &value);
                printf("Enter the position of the node:\n");
                int pos;
                scanf("%d", &pos);
                insertNth(ls, value, pos);
                break;
            }

            case 2: {
                printf("Exiting...\n");
                break;
            }

            default: {
                printf("Wrong Choice!!\n");
            }
        }

    } while(choice != 2);

    return 0;
}