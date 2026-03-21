/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;

    if(front == NULL)
    {
        front = rear = temp;
        temp->next = front;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    if(front == rear)
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != front);
}

int main()
{
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}