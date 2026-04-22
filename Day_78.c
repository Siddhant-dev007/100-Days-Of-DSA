/*Problem Statement:
Find the Minimum Spanning Tree (MST) of a weighted undirected graph
using Prim's Algorithm. Print the edges in the MST and total weight.

Input Format:
- First line contains V (vertices)
- Next V lines contain the adjacency matrix (0 means no edge)*/

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX];
int key[MAX];      // minimum weight edge to connect vertex to MST
int parent[MAX];   // stores MST
int inMST[MAX];

int minKey(int v) {
    int min = INF, idx = -1;
    for (int i = 0; i < v; i++)
        if (!inMST[i] && key[i] < min) { min = key[i]; idx = i; }
    return idx;
}

void primMST(int v) {
    for (int i = 0; i < v; i++) { key[i] = INF; inMST[i] = 0; parent[i] = -1; }
    key[0] = 0;

    for (int count = 0; count < v - 1; count++) {
        int u = minKey(v);
        inMST[u] = 1;
        for (int w = 0; w < v; w++) {
            if (graph[u][w] && !inMST[w] && graph[u][w] < key[w]) {
                key[w] = graph[u][w];
                parent[w] = u;
            }
        }
    }

    int totalWeight = 0;
    printf("MST Edges (Prim's):\n");
    for (int i = 1; i < v; i++) {
        printf("  %d -- %d  weight: %d\n", parent[i], i, graph[parent[i]][i]);
        totalWeight += graph[parent[i]][i];
    }
    printf("Total MST Weight: %d\n", totalWeight);
}

int main() {
    int v; scanf("%d", &v);
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            scanf("%d", &graph[i][j]);
    primMST(v);
    return 0;
}
