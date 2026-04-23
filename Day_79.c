/*Problem Statement:
Find shortest distances from source vertex 0 to all other vertices
using Dijkstra's Algorithm with an edge list (weighted directed graph).

Input Format:
- First line contains V (vertices) and E (edges)
- Next E lines: u v weight (directed weighted edge from u to v)*/

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int dist[MAX], visited[MAX];
int graph[MAX][MAX]; // adjacency matrix with weights

int minDist(int v) {
    int min = INF, idx = -1;
    for (int i = 0; i < v; i++)
        if (!visited[i] && dist[i] < min) { min = dist[i]; idx = i; }
    return idx;
}

void dijkstra(int v) {
    for (int i = 0; i < v; i++) { dist[i] = INF; visited[i] = 0; }
    dist[0] = 0;

    for (int c = 0; c < v - 1; c++) {
        int u = minDist(v);
        if (u == -1) break;
        visited[u] = 1;
        for (int w = 0; w < v; w++) {
            if (!visited[w] && graph[u][w] &&
                dist[u] != INF && dist[u] + graph[u][w] < dist[w])
                dist[w] = dist[u] + graph[u][w];
        }
    }

    printf("Single Source Shortest Paths from vertex 0:\n");
    for (int i = 0; i < v; i++)
        printf("  To %d : %s\n", i, dist[i] == INF ? "INF" : ""), printf("  To %d : %d\n", i, dist[i]);
}

int main() {
    int v, e; scanf("%d %d", &v, &e);
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++) graph[i][j] = 0;
    for (int i = 0; i < e; i++) {
        int u, w, wt; scanf("%d %d %d", &u, &w, &wt);
        graph[u][w] = wt;
    }
    printf("Single Source Shortest Paths from vertex 0:\n");
    dijkstra(v);
    for (int i = 0; i < v; i++)
        printf("  Vertex %d : %d\n", i, dist[i] == INF ? -1 : dist[i]);
    return 0;
}
