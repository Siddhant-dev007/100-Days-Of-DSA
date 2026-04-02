/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree function
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end) return NULL;

    // Pick current root from preorder
    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = newNode(curr);

    // If leaf node
    if (start == end)
        return root;

    // Find root in inorder
    int inIndex = findIndex(inorder, start, end, curr);

    // Build left and right subtree
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Print inorder (to verify)
void printInorder(struct Node* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int preorder[1000], inorder[1000];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    // Print inorder to verify
    printInorder(root);

    return 0;
}