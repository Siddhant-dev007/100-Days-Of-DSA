/*Problem Statement:
Perform Topological Sort on a Directed Acyclic Graph (DAG) using
Kahn's Algorithm (BFS-based).

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
int inDegree[MAX];

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
    inDegree[v]++;
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < v; i++) {
        adjList[i] = NULL;
        inDegree[i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    // Queue all vertices with in-degree 0
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < v; i++)
        if (inDegree[i] == 0)
            queue[rear++] = i;

    int count = 0;
    printf("Topological Sort (Kahn's BFS): ");

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        struct Node* node = adjList[curr];
        while (node) {
            inDegree[node->dest]--;
            if (inDegree[node->dest] == 0)
                queue[rear++] = node->dest;
            node = node->next;
        }
    }

    printf("\n");

    if (count != v)
        printf("Graph has a cycle - topological sort not possible\n");

    return 0;
}
