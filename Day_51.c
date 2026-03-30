/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values*/

#include <stdio.h>
#include <stdlib.h>

// Structure of BST node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val) {
            root = root->left;   // go left
        } else if (p > root->val && q > root->val) {
            root = root->right;  // go right
        } else {
            return root;         // this is LCA
        }
    }
    return NULL;
}

// Inorder traversal (optional)
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    int n, val, p, q;
    struct TreeNode* root = NULL;

    // Input
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter two node values: ");
    scanf("%d %d", &p, &q);

    // Find LCA
    struct TreeNode* lca = findLCA(root, p, q);

    if (lca != NULL) {
        printf("LCA of %d and %d is: %d\n", p, q, lca->val);
    } else {
        printf("LCA not found.\n");
    }

    return 0;
}