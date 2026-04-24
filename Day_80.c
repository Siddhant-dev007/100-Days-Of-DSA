/*Problem Statement:
Find shortest distances between all pairs of vertices using
Floyd-Warshall Algorithm. Also detect negative weight cycles.

Input Format:
- First line contains V (vertices)
- Next V lines contain the weighted adjacency matrix
  (0 on diagonal, -1 means no edge)*/

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 99999

int dist[MAX][MAX];

void floydWarshall(int v) {
    for (int k = 0; k < v; k++)
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    // Check negative cycle
    for (int i = 0; i < v; i++)
        if (dist[i][i] < 0) { printf("Negative weight cycle detected!\n"); return; }

    printf("All-Pairs Shortest Distances:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF) printf("%5s", "INF");
            else                   printf("%5d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int v; scanf("%d", &v);
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++) {
            int x; scanf("%d", &x);
            if (x == -1) dist[i][j] = INF;
            else         dist[i][j] = x;
        }
    floydWarshall(v);
    return 0;
}
