/*Level Order Traversal

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

/* Queue implementation */
Node* queue[100];
int front = 0, rear = -1;

void enqueue(Node* node) {
    queue[++rear] = node;
}

Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

/* Level Order Traversal */
void levelOrder(Node* root) {
    if(root == NULL) return;

    enqueue(root);

    while(!isEmpty()) {
        Node* curr = dequeue();
        printf("%d ", curr->data);

        if(curr->left)
            enqueue(curr->left);

        if(curr->right)
            enqueue(curr->right);
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter node value: ");
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}