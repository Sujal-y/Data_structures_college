// Write a C program to implement Breadth First Search (BFS)
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return (q->rear == -1);
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void BFS(int graph[][MAX_VERTICES], int numVertices, int startVertex) {
    struct Queue* q = createQueue();

    int visited[MAX_VERTICES] = {0};

    visited[startVertex] = 1;
    enqueue(q, startVertex);
    printf("BFS Traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; ++i) {
            if (graph[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
    free(q);
}

int main() {
    int numVertices = 5;

    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    int startVertex;
    printf("Enter the starting vertex (0 to %d): ", numVertices - 1);
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= numVertices) {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    BFS(graph, numVertices, startVertex);

    return 0;
}
