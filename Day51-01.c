/*Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create Node
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

// Find LCA
struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    
    while (root != NULL) {
      
        if (p < root->val && q < root->val) {
            root = root->left;
        }
    
        else if (p > root->val && q > root->val) {
            root = root->right;
        }
   
        else {
            return root;
        }
    }
    
    return NULL;
}

int main() {
    int n, val, p, q;
    struct TreeNode* root = NULL;

    // Input
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }
    {
        printf("Enter two node values to find LCA: ");
    

    scanf("%d %d", &p, &q);
    }
    // Find LCA
    struct TreeNode* lca = findLCA(root, p, q);

    // Output
    if (lca != NULL)
        printf("%d\n", lca->val);

    return 0;
}