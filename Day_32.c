/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)
*/

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
        top--;
}

void display()
{
    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        pop();
    }

    display();

    return 0;
}