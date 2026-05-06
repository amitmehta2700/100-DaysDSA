/*Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/

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

/* Build tree from level order */
Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;

    Node* nodes[n];

    for(int i = 0; i < n; i++) {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

/* LCA function */
Node* findLCA(Node* root, int n1, int n2) {
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    Node* left = findLCA(root->left, n1, n2);
    Node* right = findLCA(root->right, n1, n2);

    if(left && right)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        printf("Enter value for node %d (use -1 for NULL): ", i + 1);
        scanf("%d", &arr[i]);
    }

    int n1, n2;
    printf("Enter two values to find their LCA: ");

    scanf("%d %d", &n1, &n2);

    Node* root = buildTree(arr, n);

    Node* lca = findLCA(root, n1, n2);

    if(lca)
        printf("%d", lca->data);

    return 0;
}