/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index])
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
            break;
    }
}

void heapifyDown(int index)
{
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int x)
{
    heap[size] = x;
    heapifyUp(size);
    size++;
}

void extractMin()
{
    if(size == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

void peek()
{
    if(size == 0)
        printf("Heap is empty\n");
    else
        printf("%d\n", heap[0]);
}

int main()
{
    int N, x;
    char op[20];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "extractMin") == 0)
        {
            extractMin();
        }
        else if(strcmp(op, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}