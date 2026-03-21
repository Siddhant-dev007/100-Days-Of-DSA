/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
int count = 0;

void push_front(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = front;

    if(front != NULL)
        front->prev = temp;
    else
        rear = temp;

    front = temp;
    count++;
}

void push_back(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = rear;

    if(rear != NULL)
        rear->next = temp;
    else
        front = temp;

    rear = temp;
    count++;
}

void pop_front()
{
    if(front == NULL)
        return;

    struct node *temp = front;
    front = front->next;

    if(front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    free(temp);
    count--;
}

void pop_back()
{
    if(rear == NULL)
        return;

    struct node *temp = rear;
    rear = rear->prev;

    if(rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    free(temp);
    count--;
}

void show_front()
{
    if(front != NULL)
        printf("%d\n", front->data);
}

void show_back()
{
    if(rear != NULL)
        printf("%d\n", rear->data);
}

void empty()
{
    if(count == 0)
        printf("true\n");
    else
        printf("false\n");
}

void size()
{
    printf("%d\n", count);
}

void clear()
{
    while(front != NULL)
        pop_front();
}

void reverse()
{
    struct node *temp = NULL;
    struct node *current = front;

    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL)
        front = temp->prev;

    struct node *t = front;
    while(t->next != NULL)
        t = t->next;
    rear = t;
}

void sort()
{
    if(front == NULL)
        return;

    struct node *i, *j;
    int temp;

    for(i = front; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
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
    int n, x;
    char op[30];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op,"push_front")==0)
        {
            scanf("%d",&x);
            push_front(x);
        }
        else if(strcmp(op,"push_back")==0)
        {
            scanf("%d",&x);
            push_back(x);
        }
        else if(strcmp(op,"pop_front")==0)
            pop_front();

        else if(strcmp(op,"pop_back")==0)
            pop_back();

        else if(strcmp(op,"front")==0)
            show_front();

        else if(strcmp(op,"back")==0)
            show_back();

        else if(strcmp(op,"empty")==0)
            empty();

        else if(strcmp(op,"size")==0)
            size();

        else if(strcmp(op,"reverse")==0)
            reverse();

        else if(strcmp(op,"sort")==0)
            sort();

        else if(strcmp(op,"clear")==0)
            clear();

        else if(strcmp(op,"display")==0)
            display();
    }

    return 0;
}