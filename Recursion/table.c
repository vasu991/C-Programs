#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by hp on 2/13/2024.
//
#include<stdio.h>
void table(int n, int x) {
    if(x > 10) {
        return;
    }
    int p = x*n;
    printf("%d x %d = %d\n", n, x, p);
    table(n, x+1);
}
int main() {
    int n;
    printf("enter the number whose table is to be printed:\n");
    scanf("%d", &n);
    table(n, 1);
}

#pragma clang diagnostic pop