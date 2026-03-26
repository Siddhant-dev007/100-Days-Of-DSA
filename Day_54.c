/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)
*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for level order
struct TreeNode* queue[1000];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Zigzag traversal
void zigzagTraversal(struct TreeNode* root) {
    if (!root) return;

    enqueue(root);
    int leftToRight = 1;

    while (!isEmpty()) {
        int size = rear - front;
        int arr[size];

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue();

            int index = leftToRight ? i : (size - 1 - i);
            arr[index] = node->val;

            if (node->left) enqueue(node->left);
            if (node->right) enqueue(node->right);
        }

        // Print current level
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }

        leftToRight = !leftToRight; // toggle direction
    }
}