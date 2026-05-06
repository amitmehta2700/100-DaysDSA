 /*BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// Structure of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
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
struct TreeNode* searchBST(struct TreeNode* root, int key) {
    if (root == NULL || root->val == key) {
        return root;
    }

    if (key < root->val) {
        return searchBST(root->left, key);
    }

    return searchBST(root->right, key);
}

// Inorder Traversal (for display)
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

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input elements
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Display BST (Inorder)
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    // Search key
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct TreeNode* result = searchBST(root, key);

    // Output result
    if (result != NULL) {
        printf("Value %d found in BST\n", key);
    } else {
        printf("Value %d NOT found in BST\n", key);
    }

    return 0;
}