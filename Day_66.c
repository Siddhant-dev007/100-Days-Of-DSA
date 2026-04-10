/*Problem Statement:
Detect whether a cycle exists in a directed graph using DFS.
Uses the "white-grey-black" coloring technique.

Input Format:
- First line contains V (vertices) and E (edges)
- Next E lines each contain two integers u and v (directed edge from u to v)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
// color: 0 = white (unvisited), 1 = grey (in stack), 2 = black (done)

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adjList[MAX];
int color[MAX];

struct Node* newNode(int dest) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = dest;
    node->next = NULL;
    return node;
}

void addEdge(int u, int v) {
    // Directed edge
    struct Node* node = newNode(v);
    node->next = adjList[u];
    adjList[u] = node;
}

int dfs(int v) {
    color[v] = 1; // grey: currently in recursion stack

    struct Node* curr = adjList[v];
    while (curr) {
        if (color[curr->dest] == 1)
            return 1; // back edge => cycle
        if (color[curr->dest] == 0) {
            if (dfs(curr->dest))
                return 1;
        }
        curr = curr->next;
    }

    color[v] = 2; // black: fully processed
    return 0;
}

int hasCycle(int v) {
    for (int i = 0; i < v; i++)
        if (color[i] == 0)
            if (dfs(i)) return 1;
    return 0;
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < v; i++) {
        adjList[i] = NULL;
        color[i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    if (hasCycle(v))
        printf("Cycle detected in the directed graph\n");
    else
        printf("No cycle detected\n");

    return 0;
}
