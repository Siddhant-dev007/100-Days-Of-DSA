/*Problem Statement:
Perform Topological Sort on a Directed Acyclic Graph (DAG) using DFS.
Topological order: for every edge u->v, u appears before v.

Input Format:
- First line contains V (vertices) and E (edges)
- Next E lines each contain two integers u and v (directed edge from u to v)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

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
}

void dfs(int v) {
    visited[v] = 1;

    struct Node* curr = adjList[v];
    while (curr) {
        if (!visited[curr->dest])
            dfs(curr->dest);
        curr = curr->next;
    }

    // Push to stack after all descendants are processed
    stack[++top] = v;
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

    for (int i = 0; i < v; i++)
        if (!visited[i])
            dfs(i);

    printf("Topological Sort (DFS): ");
    while (top >= 0)
        printf("%d ", stack[top--]);
    printf("\n");

    return 0;
}
