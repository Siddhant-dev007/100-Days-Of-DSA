/*Problem Statement:
Check if an undirected graph is connected (i.e., every vertex is reachable
from every other vertex) using BFS.

Input Format:
- First line contains V (vertices) and E (edges)
- Next E lines each contain two integers u and v (edge between u and v)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node { int dest; struct Node* next; };
struct Node* adjList[MAX];
int visited[MAX];
int queue[MAX];
int front, rear;

struct Node* newNode(int dest) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->dest = dest; n->next = NULL; return n;
}

void addEdge(int u, int v) {
    struct Node* n = newNode(v); n->next = adjList[u]; adjList[u] = n;
    n = newNode(u); n->next = adjList[v]; adjList[v] = n;
}

void bfs(int start) {
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        int v = queue[front++];
        for (struct Node* c = adjList[v]; c; c = c->next)
            if (!visited[c->dest]) { visited[c->dest] = 1; queue[rear++] = c->dest; }
    }
}

int main() {
    int v, e; scanf("%d %d", &v, &e);
    for (int i = 0; i < v; i++) { adjList[i] = NULL; visited[i] = 0; }
    front = rear = 0;
    for (int i = 0; i < e; i++) {
        int u, w; scanf("%d %d", &u, &w); addEdge(u, w);
    }
    bfs(0);
    int connected = 1;
    for (int i = 0; i < v; i++) if (!visited[i]) { connected = 0; break; }
    printf(connected ? "Graph is connected\n" : "Graph is NOT connected\n");
    return 0;
}
