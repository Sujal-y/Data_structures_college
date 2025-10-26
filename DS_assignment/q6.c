// Imagine a print server with a circular queue of capacity 5 to manage incoming print
// jobs.
// Initial State: The queue is empty. front = -1, rear = -1.
// Enqueue Operations:
// a. Job A arrives: enQueue(Job A). Queue: [Job A, _, _, _, _], front = 0, rear = 0.
// b. Job B arrives: enQueue(Job B). Queue: [Job A, Job B, _, _, _], front = 0, rear = 1.
// c. Job C arrives: enQueue(Job C). Queue: [Job A, Job B, Job C, _, _], front = 0,rear = 2.
// d. Job D arrives: enQueue(Job D). Queue: [Job A, Job B, Job C, Job D, _], front =
// 0, rear = 3.
// e. Job E arrives: enQueue(Job E). Queue: [Job A, Job B, Job C, Job D, Job E], front
// = 0, rear = 4. (Queue is full)

// Dequeue Operations:
// f. Print server processes Job A: deQueue(). Queue: [_, Job B, Job C, Job D, Job
// E], front = 1, rear = 4.
// g. Print server processes Job B: deQueue(). Queue: [_, _, Job C, Job D, Job E],
// front = 2, rear = 4.

// Enqueue with Wrap-around:
// h. Job F arrives: enQueue(Job F). Since the queue is circular, Job F is placed at
// index 0. Queue: [Job F, _, Job C, Job D, Job E], front = 2, rear = 0.
// i. Job G arrives: enQueue(Job G). Queue: [Job F, Job G, Job C, Job D, Job E],
// front = 2, rear = 1.

// Implement the Circular Queue: Provide a detailed implementation of the circular
// queue data structure (using an array) in C programming language. Include methods
// for enQueue, deQueue, isFull, isEmpty, and peek (to view the front element without
// removing)

#include <stdio.h>

#define CAPACITY 5

typedef struct {
    char items[CAPACITY];
    int front;
    int rear;
} CircularQueue;

void initialize_queue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int is_full(CircularQueue* q) {
    return ((q->rear + 1) % CAPACITY == q->front);
}

int is_empty(CircularQueue* q) {
    return (q->front == -1);
}

void en_queue(CircularQueue* q, char item) {
    if (is_full(q)) {
        printf("Queue is full. Cannot enqueue Job %c.\n", item);
        return;
    }
    if (is_empty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % CAPACITY;
    q->items[q->rear] = item;
    printf("Enqueued Job %c. (front=%d, rear=%d)\n", item, q->front, q->rear);
}

char de_queue(CircularQueue* q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return '\0';
    }

    char item = q->items[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % CAPACITY;
    }

    printf("Dequeued Job %c. (front=%d, rear=%d)\n", item, q->front, q->rear);
    return item;
}

char peek(CircularQueue* q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot peek.\n");
        return '\0';
    }
    return q->items[q->front];
}

void display_queue(CircularQueue* q) {
    char display_arr[CAPACITY];
    for (int k = 0; k < CAPACITY; k++) {
        display_arr[k] = '_';
    }

    if (!is_empty(q)) {
        int i = q->front;
        while (1) {
            display_arr[i] = q->items[i];
            if (i == q->rear) {
                break;
            }
            i = (i + 1) % CAPACITY;
        }
    }

    printf("Queue: [");
    for (int k = 0; k < CAPACITY; k++) {
        printf("%c", display_arr[k]);
        if (k < CAPACITY - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

int main() {
    CircularQueue q;
    initialize_queue(&q);

    printf("--- Initial State ---\n");
    printf("(front=%d, rear=%d)\n", q.front, q.rear);
    display_queue(&q);

    printf("--- (a) Enqueue Job A ---\n");
    en_queue(&q, 'A');
    display_queue(&q);

    printf("--- (b) Enqueue Job B ---\n");
    en_queue(&q, 'B');
    display_queue(&q);

    printf("--- (c) Enqueue Job C ---\n");
    en_queue(&q, 'C');
    display_queue(&q);

    printf("--- (d) Enqueue Job D ---\n");
    en_queue(&q, 'D');
    display_queue(&q);

    printf("--- (e) Enqueue Job E ---\n");
    en_queue(&q, 'E');
    display_queue(&q);

    printf("--- (f) Dequeue Job A ---\n");
    de_queue(&q);
    display_queue(&q);

    printf("--- (g) Dequeue Job B ---\n");
    de_queue(&q);
    display_queue(&q);

    printf("--- (h) Enqueue Job F (Wrap-around) ---\n");
    en_queue(&q, 'F');
    display_queue(&q);

    printf("--- (i) Enqueue Job G ---\n");
    en_queue(&q, 'G');
    display_queue(&q);

    printf("--- Additional Tests ---\n");
    printf("Is queue full? %s\n", is_full(&q) ? "Yes" : "No");
    printf("Attempt to enqueue Job H...\n");
    en_queue(&q, 'H');

    printf("\nPeek at front job: Job %c\n", peek(&q));

    printf("\n--- Emptying the queue ---\n");
    de_queue(&q);
    de_queue(&q);
    de_queue(&q);
    de_queue(&q);
    de_queue(&q);

    printf("\nIs queue empty? %s\n", is_empty(&q) ? "Yes" : "No");
    display_queue(&q);

    return 0;
}
