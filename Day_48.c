/*Problem: Count Leaf Nodes

Implement the solution for this problem.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // Base case
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursive case
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}