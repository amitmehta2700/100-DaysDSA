#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue Node (for storing node + HD)
struct QNode {
    struct Node* node;
    int hd;
};

// Create new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        // left child
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    // Array to store vertical lines
    int result[MAX][MAX], size[MAX] = {0};

    // Queue for BFS
    struct QNode queue[MAX];
    int front = 0, rear = 0;

    int offset = MAX / 2; // to handle negative HD

    queue[rear++] = (struct QNode){root, offset};

    int min = offset, max = offset;

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd;

        // Store node value
        result[hd][size[hd]++] = node->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (node->left)
            queue[rear++] = (struct QNode){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct QNode){node->right, hd + 1};
    }

    // Print vertical order
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d (use -1 for NULL): ", i + 1);
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}