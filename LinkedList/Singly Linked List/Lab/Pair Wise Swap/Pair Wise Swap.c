#include<stdlib.h>
#include<stdio.h>
typedef struct Node {
    int info;
    struct Node *next;
} Node;

typedef struct List {
    Node* start;
    Node* end;
} List;

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->start = NULL;
    list->end = NULL;
    return list;
}

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    return node;
}
void append(Node** left, Node** right, int info)
{

    Node* new_node
            = createNode();
    new_node->info = info;

    new_node->next = NULL;
    if (*left == NULL) {
        *left = new_node;
        *right = new_node;
        return;
    }

    (*right)->next = new_node;
    *right = new_node;
}
void pairWiseSwap(Node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    Node* prev = *head;
    Node* curr = (*head)->next;
    *head = curr;

    while (1) {
        Node* next = curr->next;
        curr->next = prev;
        if (next == NULL || next->next == NULL) {
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
}

void printList(Node* node)
{
    if(node == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("START ->");
    while (node != NULL) {
        printf(" %d ->", node->info);
        node = node->next;
    }
    printf(" END");
    printf("\n");
}

