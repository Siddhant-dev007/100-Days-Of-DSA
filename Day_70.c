/*Problem Statement:
Find the shortest path from source vertex 0 to all other vertices
using the Bellman-Ford Algorithm. Also detects negative weight cycles.

Input Format:
- First line contains V (vertices) and E (edges)
- Next E lines contain u, v, weight (directed weighted edge from u to v)*/

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

struct Edge {
    int u, v, weight;
};

struct Edge edges[MAX * MAX];
int dist[MAX];

void bellmanFord(int v, int e, int src) {
    for (int i = 0; i < v; i++) dist[i] = INF;
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j].u;
            int w = edges[j].v;
            int wt = edges[j].weight;

            if (dist[u] != INF && dist[u] + wt < dist[w])
                dist[w] = dist[u] + wt;
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < e; j++) {
        int u = edges[j].u;
        int w = edges[j].v;
        int wt = edges[j].weight;

        if (dist[u] != INF && dist[u] + wt < dist[w]) {
            printf("Graph contains a negative weight cycle\n");
            return;
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
    int v, e;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    bellmanFord(v, e, 0);

    return 0;
}
