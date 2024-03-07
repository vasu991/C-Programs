#include<stdlib.h>
typedef struct Node {
    int info;
    struct Node *next;
} Node;

void append(Node** left, Node** right, int info)
{

    Node* new_node
            = (Node*)malloc(sizeof(Node));
    new_node->info = info;

    Node* last = *left;
    new_node->next = NULL;
    if (*left == NULL) {
        *left = new_node;
        *right = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    *right = new_node;
}

void printList(Node* node)
{
    while (node != NULL) {
        printf(" %d ->", node->info);
        node = node->next;
    }
    printf(" END");
    printf("\n");
}


int size(Node *head) {
    int s = 0;
    while(head != NULL) {
        s++;
        head = head -> next;
    }
    return s;
}