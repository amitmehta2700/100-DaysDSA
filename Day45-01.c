/*Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/
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

int height(Node* root) {
    if(root == NULL)
        return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return 1 + (leftH > rightH ? leftH : rightH);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter node value (or -1 for NULL): ");
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    printf("%d", height(root));

    return 0;
}