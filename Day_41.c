/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if(rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

void display()
{
    struct node *temp = front;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int N, x;
    char op[20];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &x);
            enqueue(x);
        }
        else if(strcmp(op, "dequeue") == 0)
        {
            dequeue();
        }
    }

    display();

    return 0;
}