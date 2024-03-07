#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>

int stack[100], i, choice=0, n, top=-1;

void push ()
{
    int val;
    if (top == n)
        printf("\nOverflow");
    else
    {
        printf("Enter the value:\n");
        scanf("%d",&val);
        top = top +1;
        stack[top] = val;
    }
}

void pop ()
{
    if(top == -1)
        printf("Underflow\n");
    else
        top = top -1;
}
void show()
{
    for (i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
        printf("^\n");
    }
    printf("END\n");
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
}



#pragma clang diagnostic pop