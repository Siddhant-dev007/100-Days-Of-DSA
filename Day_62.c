/*Problem Statement:
Represent a graph using an adjacency list and print it.

Input Format:
- First line contains V (vertices) and E (edges)
- Next E lines each contain two integers u and v (edge between u and v)*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Node* adjList[100];

struct Node* newNode(int dest) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = dest;
    node->next = NULL;
    return node;
}

void addEdge(int u, int v) {
    // Add v to u's list
    struct Node* node = newNode(v);
    node->next = adjList[u];
    adjList[u] = node;

    // Add u to v's list (undirected)
    node = newNode(u);
    node->next = adjList[v];
    adjList[v] = node;
}

void printList(int v) {
    printf("Adjacency List:\n");
    for (int i = 0; i < v; i++) {
        printf("%d -> ", i);
        struct Node* curr = adjList[i];
        while (curr) {
            printf("%d ", curr->dest);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < v; i++)
        adjList[i] = NULL;

    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    printList(v);

    return 0;
}
