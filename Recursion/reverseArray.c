#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#include<stdio.h>
void rev(int *arr, int start, int end) {
    if(start >= end) {
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    rev(arr, start+1, end-1);
}
int main() {
    int arr[] = {0, 1, 2, 3, 4};
    rev(arr, 0, 4);
    for(int i = 0; i<5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
#pragma clang diagnostic pop