/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line
should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal 
(-1 indicates NULL)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for BFS
struct QNode {
    struct Node* node;
    int hd;
};

struct QNode queue[MAX];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* tempQ[MAX];
    int f = 0, r = 0;

    tempQ[r++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = tempQ[f++];

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            tempQ[r++] = curr->left;
        }
        i++;
        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            tempQ[r++] = curr->right;
        }
        i++;
    }
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    int result[MAX][MAX]; // store values
    int count[MAX] = {0}; // count per HD

    int offset = MAX / 2; // to handle negative HD

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QNode temp = dequeue();
        struct Node* node = temp.node;
        int hd = temp.hd + offset;

        result[hd][count[hd]++] = node->data;

        if (node->left)
            enqueue(node->left, temp.hd - 1);

        if (node->right)
            enqueue(node->right, temp.hd + 1);
    }

    // Print result
    for (int i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}