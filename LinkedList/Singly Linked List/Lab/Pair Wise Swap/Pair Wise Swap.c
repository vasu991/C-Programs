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
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void pairWiseSwap(Node* head)
{
    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        swap(&temp->info, &temp->next->info);
        temp = temp->next->next;
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

