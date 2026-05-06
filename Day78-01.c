
/*Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

typedef struct {
    int node;
    int weight;
} Pair;

// Min Heap
Pair heap[MAX];
int heapSize = 0;

void swap(Pair* a, Pair* b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(Pair val) {
    heap[++heapSize] = val;
    int i = heapSize;

    while (i > 1 && heap[i].weight < heap[i/2].weight) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

Pair pop() {
    Pair top = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int left = 2*i, right = 2*i+1, smallest = i;

        if (left <= heapSize && heap[left].weight < heap[smallest].weight)
            smallest = left;
        if (right <= heapSize && heap[right].weight < heap[smallest].weight)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
    return top;
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Adjacency list
    int** graph = (int**)malloc((n+1) * sizeof(int*));
    int** weight = (int**)malloc((n+1) * sizeof(int*));
    int* size = (int*)calloc(n+1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        graph[i] = (int*)malloc(2*m * sizeof(int));
        weight[i] = (int*)malloc(2*m * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        printf("Enter edge %d (u v w): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);

        graph[u][size[u]] = v;
        weight[u][size[u]++] = w;

        graph[v][size[v]] = u;
        weight[v][size[v]++] = w;
    }

    int* visited = (int*)calloc(n+1, sizeof(int));

    int totalWeight = 0;

    // Start from node 1
    push((Pair){1, 0});

    while (heapSize > 0) {
        Pair current = pop();
        int u = current.node;
        int w = current.weight;

        if (visited[u]) continue;

        visited[u] = 1;
        totalWeight += w;

        for (int i = 0; i < size[u]; i++) {
            int v = graph[u][i];
            int wt = weight[u][i];

            if (!visited[v]) {
                push((Pair){v, wt});
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}