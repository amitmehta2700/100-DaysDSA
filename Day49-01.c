/*BST Insert

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Insert in BST */
Node* insert(Node* root, int val) {
    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

/* Inorder traversal (to check BST) */
void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n, x;
    Node* root = NULL;
    printf("Enter number of nodes: ");

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &x);
        root = insert(root, x);
    }

    inorder(root);

    return 0;
}