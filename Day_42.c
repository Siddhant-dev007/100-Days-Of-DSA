/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers*/

#include <stdio.h>

#define MAX 100

int queue[MAX], stack[MAX];
int front = 0, rear = -1;
int top = -1;

void enqueue(int x)
{
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int N, x;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    while(front <= rear)
    {
        push(dequeue());
    }

    front = 0;
    rear = -1;

    while(top != -1)
    {
        enqueue(pop());
    }

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}