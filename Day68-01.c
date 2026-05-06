/*Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Node for adjacency list */
struct Node {
    int vertex;
    struct Node* next;
};

/* Graph structure */
struct Graph {
    int V;
    struct Node** adjLists;
};

/* Queue */
int queue[MAX];
int front = 0, rear = -1;

/* Enqueue */
void enqueue(int x) {
    queue[++rear] = x;
}

/* Dequeue */
int dequeue() {
    return queue[front++];
}

/* Check if queue empty */
int isEmpty() {
    return front > rear;
}

/* Create node */
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/* Create graph */
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjLists = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

/* Add edge (DIRECTED) */
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;
}

/* Kahn's Algorithm */
void topoSort(struct Graph* graph) {
    int indegree[MAX] = {0};

    /* Step 1: Calculate in-degrees */
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    /* Step 2: Push nodes with indegree 0 */
    for (int i = 0; i < graph->V; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;

    /* Step 3: Process queue */
    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);
        count++;

        struct Node* temp = graph->adjLists[curr];

        while (temp) {
            indegree[temp->vertex]--;

            if (indegree[temp->vertex] == 0)
                enqueue(temp->vertex);

            temp = temp->next;
        }
    }

    /* Cycle check */
    if (count != graph->V)
        printf("\nCycle exists! Topological sort not possible");
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;

    /* Input edges */
    for (int i = 0; i < m; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topoSort(graph);

    return 0;
}