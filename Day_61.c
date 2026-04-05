/*Problem Statement:
Represent a graph using an adjacency matrix and print it.

Input Format:
- First line contains V (vertices) and E (edges)
- Next E lines each contain two integers u and v (edge between u and v)*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // undirected graph
}

void printMatrix(int v) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);

    // Initialize matrix to 0
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            adj[i][j] = 0;

    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    printMatrix(v);

    return 0;
}
