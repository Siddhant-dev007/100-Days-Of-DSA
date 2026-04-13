/*Problem Statement:
Find the shortest path from source vertex 0 to all other vertices
using Dijkstra's Algorithm (greedy approach with adjacency matrix).

Input Format:
- First line contains V (vertices)
- Next V lines contain the adjacency matrix (0 means no edge)*/

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];

// Pick vertex with minimum distance not yet visited
int minDistance(int v) {
    int min = INF, minIdx = -1;
    for (int i = 0; i < v; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void dijkstra(int v, int src) {
    for (int i = 0; i < v; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < v - 1; count++) {
        int u = minDistance(v);
        if (u == -1) break;
        visited[u] = 1;

        for (int w = 0; w < v; w++) {
            if (!visited[w] && graph[u][w] != 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][w] < dist[w]) {
                dist[w] = dist[u] + graph[u][w];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", src);
    for (int i = 0; i < v; i++) {
        if (dist[i] == INF)
            printf("Vertex %d : INF\n", i);
        else
            printf("Vertex %d : %d\n", i, dist[i]);
    }
}

int main() {
    int v;
    scanf("%d", &v);

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            scanf("%d", &graph[i][j]);

    dijkstra(v, 0);

    return 0;
}
