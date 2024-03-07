#include<stdio.h>
#include<stdlib.h>

void insert(int **arr, int *size, int index, int value) {
    *size += 1;
    *arr = realloc(*arr, sizeof(int) * (*size));
    for(int i = *size - 1; i > index; i--) {
        (*arr)[i] = (*arr)[i-1];
    }
    (*arr)[index] = value;
}

void delete(int **arr, int *size, int index) {

    for(int i = index; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i+1];
    }
    *size -= 1;
    *arr = realloc(*arr, sizeof(int) * (*size));
}
void display(int **arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", (*arr)[i]);
    }
    printf("Size: %d", size);
    printf("\n");
}

int main() {
    int *arr = (int *)malloc(sizeof(int) * 5);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;

    int size = 5;
    display(&arr, size);
    delete(&arr, &size, 2);
    display(&arr, size);
    insert(&arr, &size, 1, 10);
    display(&arr, size);
    free(arr);
    return 0;
}
