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

    new_node->next = NULL;
    if (*left == NULL) {
        *left = new_node;
        *right = new_node;
        return;
    }

    (*right)->next = new_node;
    *right = new_node;
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