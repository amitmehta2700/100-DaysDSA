/*Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include <stdio.h>

#define MAX 10

int queue[MAX], front = 0, rear = -1;
int visited[MAX];

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

int main() {
    int n, i, j, s;
    int adj[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &s);

    // Initialize visited
    for(i = 0; i < n; i++)
        visited[i] = 0;

    // BFS start
    enqueue(s);
    visited[s] = 1;

    printf("BFS Traversal: ");

    while(front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for(i = 0; i < n; i++) {
            if(adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}