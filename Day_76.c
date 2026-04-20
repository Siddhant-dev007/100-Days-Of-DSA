/*Problem Statement:
Count the number of connected components in an undirected graph using DFS.

Input Format:
- First line contains V (vertices) and E (edges)
- Next E lines each contain two integers u and v (edge between u and v)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node { int dest; struct Node* next; };
struct Node* adjList[MAX];
int visited[MAX];

struct Node* newNode(int dest) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->dest = dest; n->next = NULL; return n;
}

void addEdge(int u, int v) {
    struct Node* n = newNode(v); n->next = adjList[u]; adjList[u] = n;
    n = newNode(u); n->next = adjList[v]; adjList[v] = n;
}

void dfs(int v) {
    visited[v] = 1;
    for (struct Node* c = adjList[v]; c; c = c->next)
        if (!visited[c->dest]) dfs(c->dest);
}

int main() {
    int v, e; scanf("%d %d", &v, &e);
    for (int i = 0; i < v; i++) { adjList[i] = NULL; visited[i] = 0; }
    for (int i = 0; i < e; i++) {
        int u, w; scanf("%d %d", &u, &w); addEdge(u, w);
    }
    int comp = 0;
    for (int i = 0; i < v; i++) if (!visited[i]) { dfs(i); comp++; }
    printf("Number of connected components: %d\n", comp);
    return 0;
}
