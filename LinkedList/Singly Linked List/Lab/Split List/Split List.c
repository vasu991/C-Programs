#include<stdlib.h>
typedef struct Node {
    int info;
    struct Node *next;
} Node;

typedef struct List {
    Node* start;
} List;

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->start = NULL;
    return list;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the list
void appendNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* last = *headRef;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

// Function to split the linked list P into Q and R
void split(Node* P, Node** Q, Node** R) {
    int position = 1;
    struct Node* current = P;

    while (current != NULL) {
        if (position % 2 != 0) {
            appendNode(Q, current->info);
        } else {
            appendNode(R, current->info);
        }
        current = current->next;
        position++;
    }
}

void printList(Node* head)
{
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("START ->");
    while (head != NULL) {
        printf(" %d ->", head->info);
        head = head->next;
    }
    printf(" END");
    printf("\n");
}