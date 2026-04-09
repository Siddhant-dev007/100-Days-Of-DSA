/*Problem Statement:
Detect whether a cycle exists in an undirected graph using DFS.

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

// Returns 1 if cycle found
int dfs(int v, int parent) {
    visited[v] = 1;

    struct Node* curr = adjList[v];
    while (curr) {
        if (!visited[curr->dest]) {
            if (dfs(curr->dest, v))
                return 1;
        } else if (curr->dest != parent) {
            // Found a back edge => cycle
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int hasCycle(int v) {
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
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

    if (hasCycle(v))
        printf("Cycle detected in the graph\n");
    else
        printf("No cycle detected\n");

    return 0;
}
