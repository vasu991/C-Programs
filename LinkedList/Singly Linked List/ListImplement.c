#include<stdlib.h>
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
            = (Node*)malloc(sizeof(Node));
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

void deleteSecondLast(Node* ptr) {
    Node* temp = ptr;
    Node* prev = NULL;
    if(temp->next == NULL) {
        printf("Only One Node. Can not DELETE Second Last..\n");
        return;
    }
    while(temp->next->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if(prev == NULL) {
        prev = temp;
        ptr = ptr->next;
        free(prev);
    }

    else {
        prev->next = temp->next;
        free(temp);
    }
}

int deleteByValue(Node** left, Node** right, int key) {
    if(*left == NULL) {
        printf("List is empty!\n");
        return -1;
    }
    int deleted;
    Node* temp = *left;
    Node* prev = NULL;

    while((temp != NULL) && (key != temp->info)) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {// not found
        printf("Key not found!\n");
        return -1;
    }

    if(*right == temp && *left == temp) {// only element
        deleted = temp->info;
        *left = NULL;
        *right = NULL;
        free(temp);
        return deleted;
    }
    if(prev == NULL) {// first element
        deleted = temp->info;
        *left = (*left)->next;
        free(temp);
        return deleted;
    }
    if(temp->next == NULL) {// last element
        deleted = temp->info;
        *right = prev;
        (*right)->next = NULL;
        free(temp);
        return deleted;
    }
    deleted = temp->info;
    prev->next = temp->next;
    free(temp);
    return deleted;
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


List* connectLists(List* list1, List* list2) {
    Node* temp1 = list1->start;
    Node* temp2 = list2->start;

    List* new_list = (List*) malloc(sizeof(List));

    new_list->start = NULL;

    Node* current = NULL;

    while (temp1 != NULL) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->info = temp1->info;
        node->next = NULL;

        if (new_list->start == NULL) {
            new_list->start = node;
            current = node;
        } else {
            current->next = node;
            current = current->next;
        }
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->info = temp2->info;
        node->next = NULL;

        if (new_list->start == NULL) {
            new_list->start = node;
            current = node;
        } else {
            current->next = node;
            current = current->next;
        }
        if(temp2->next == NULL) {
            new_list->end = temp2;
        }
        temp2 = temp2->next;
    }
    return new_list;
}


void insertAscending(Node** left, Node** right, int info) {
    Node* node = (Node*) malloc(sizeof(Node));
    if(node == NULL) {
        printf("Memory OVERFLOW.\n");
        return;
    }
    node->info = info;
    node->next = NULL;
    if(*left == NULL) {
        *left = node;
        *right = node;
    }
    else {
        if(info < (*left)->info) {
            node->next = *left;
            *left = node;
        }
        else if(info > (*right)->info) {
            (*right)->next = node;
            *right = node;
        }
        else {
            Node* temp = *left;
            while(temp->info < info) {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
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


int size(Node *head) {
    int s = 0;
    while(head != NULL) {
        s++;
        head = head -> next;
    }
    return s;
}