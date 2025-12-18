#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_QUEUE 100
#define MAX_STACK 100

// ---------------- Graph Representation ----------------
struct node {
    int vertex;
    struct node* next;
};

struct Graph {
    int numVertices;
    struct node* adjLists[MAX_VERTICES];
};

// Create a new adjacency node
struct node* createNode(int v) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct node* n = createNode(dest);
    n->next = graph->adjLists[src];
    graph->adjLists[src] = n;

    n = createNode(src); // undirected
    n->next = graph->adjLists[dest];
    graph->adjLists[dest] = n;
}

// Print graph adjacency lists
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// ---------------- BFS using array queue ----------------
int queue[MAX_QUEUE];
int front = 0, rear = 0;

void enqueue(int v) {
    if (rear == MAX_QUEUE) {
        printf("Queue Overflow!\n");
        return;
    }
    queue[rear++] = v;
}

int dequeue() {
    if (front == rear) return -1; // empty
    return queue[front++];
}

int isEmptyQueue() {
    return front == rear;
}

void BFS(struct Graph* graph, int start) {
    int visited[MAX_VERTICES] = {0};
    front = rear = 0; // reset queue
    enqueue(start);
    visited[start] = 1;

    printf("BFS: ");
    while (!isEmptyQueue()) {
        int v = dequeue();
        printf("%d ", v);

        struct node* temp = graph->adjLists[v];
        while (temp != NULL) {
            int adjV = temp->vertex;
            if (!visited[adjV]) {
                enqueue(adjV);
                visited[adjV] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// ---------------- DFS using array stack ----------------
int stack[MAX_STACK];
int top = -1;

void push(int v) {
    if (top == MAX_STACK - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = v;
}

int pop() {
    if (top == -1) return -1; // empty
    return stack[top--];
}

int isEmptyStack() {
    return top == -1;
}

void DFS(struct Graph* graph, int start) {
    int visited[MAX_VERTICES] = {0};
    top = -1;
    push(start);

    printf("DFS: ");
    while (!isEmptyStack()) {
        int v = pop();
        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
        }

        struct node* temp = graph->adjLists[v];
        while (temp != NULL) {
            int adjV = temp->vertex;
            if (!visited[adjV]) {
                push(adjV);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// ---------------- Main ----------------
int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printf("Graph adjacency lists:\n");
    printGraph(graph);

    printf("\n");
    BFS(graph, 0);
    DFS(graph, 0);

    return 0;
}
