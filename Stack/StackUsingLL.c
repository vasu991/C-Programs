#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node *next;
} Node;

int peek(Node* node) {
    return node->info;
}

void push(Node** top, int info) {
    Node* node
            = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        printf("Memory Overflow!\n");
        return;
    }

    node->info = info;
    node->next = *top;
    *top = node;
}

int pop(Node** top) {
    if(*top == NULL) {
        printf("Stack Empty\n");
        return '\0';
    }
    int val = (*top)->info;
    Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    return val;
}

void display(Node* top) {
    Node* temp = top;
    while(temp != NULL) {
        printf("%d\n", peek(temp));
        printf("^\n");
        temp = temp->next;
    }
    printf("END\n");
}

int main() {
    Node* top = NULL;
    int n;

    do {
        printf("MENU FOR STACK\n");
        printf("---------------------------------\n");
        printf("1. For adding data.\n");
        printf("2. For displaying all the nodes.\n");
        printf("3. For deleting form top.\n");
        printf("4. EXIT\n");
        scanf("%d", &n);
        switch(n) {
            case 1: {
                int val;
                printf("Enter the value:\n");
                scanf("%d", &val);
                push(&top, val);
                printf("Added value to top.\n");
            } break;

            case 2: {
                display(top);
            } break;

            case 3: {
                pop(&top);
                printf("Deleted from top.\n");
            } break;

            case 4: {
                printf("exiting...\n");
                return 0;
            }

            default:
                printf("Wrong input!\n");
        }
    } while(n != 4);


    return 0;
}
#pragma clang diagnostic pop