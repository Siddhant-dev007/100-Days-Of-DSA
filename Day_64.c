/*Problem Statement:
Perform Breadth First Search (BFS) traversal of a graph starting from vertex 0.

Input Format:
- First line contains V (vertices) and E (edges)
- Next E lines each contain two integers u and v (edge between u and v)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];

// Queue
int queue[MAX];
int front = 0, rear = 0;

struct Node* newNode(int dest) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = dest;
    node->next = NULL;
    return node;
}

void addEdge(int u, int v) {
    struct Node* node = newNode(v);
    node->next = adjList[u];
    adjList[u] = node;

    node = newNode(u);
    node->next = adjList[v];
    adjList[v] = node;
}

void enqueue(int v) { queue[rear++] = v; }
int dequeue()       { return queue[front++]; }
int isEmpty()       { return front == rear; }

void bfs(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        struct Node* curr = adjList[v];
        while (curr) {
            if (!visited[curr->dest]) {
                visited[curr->dest] = 1;
                enqueue(curr->dest);
            }
            curr = curr->next;
        }
    }
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < v; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    printf("BFS Traversal: ");
    bfs(0);
    printf("\n");

    return 0;
}
