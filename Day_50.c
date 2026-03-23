/*Problem: BST Search

Implement the solution for this problem.*/


#include <stdio.h>
#include <stdlib.h>

// Define structure
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

// Insert into BST (to build tree)
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val) {
            return root;
        } else if (val < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

// Inorder traversal (for checking)
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int n, val, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Enter value to search: ");
    scanf("%d", &key);

    struct TreeNode* result = searchBST(root, key);

    if (result != NULL) {
        printf("Value %d found in BST.\n", key);
    } else {
        printf("Value %d not found in BST.\n", key);
    }

    return 0;
}