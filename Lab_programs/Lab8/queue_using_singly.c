//Implement a queue using a singly linked list with enqueue and dequeue operations.

#include <stdio.h>
#include <stdlib.h>

// Define the node and queue structures
struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Add an element to the rear of the queue (enqueue)
void enqueue(struct Queue* q, int data) {
    // Create the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    // If the queue is empty, the new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Link the last node to the new node and update rear
    q->rear->next = newNode;
    q->rear = newNode;
}

// Remove an element from the front of the queue (dequeue)
int dequeue(struct Queue* q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        return -1; // Return an error value
    }

    // Store the old front node to free it later
    struct Node* temp = q->front;
    int data = temp->data;

    // Move front to the next node
    q->front = q->front->next;

    // If the queue just became empty, set rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp); // Free the memory of the removed node
    return data;
}

// Main function to demonstrate the queue
int main() {
    // Initialize the queue
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL) {
         printf("Memory allocation failed\n");
         return 1;
    }
    q->front = q->rear = NULL;

    // --- Test Operations ---
    printf("Enqueuing 10\n");
    enqueue(q, 10);
    printf("Enqueuing 20\n");
    enqueue(q, 20);

    printf("Dequeued: %d\n", dequeue(q)); // Dequeues 10
    printf("Dequeued: %d\n", dequeue(q)); // Dequeues 20

    // Test empty dequeue
    int val = dequeue(q);
    if (val == -1) {
        printf("Queue is empty\n");
    }

    // Add one more item
    printf("Enqueuing 30\n");
    enqueue(q, 30);
    printf("Dequeued: %d\n", dequeue(q)); // Dequeues 30

    free(q);
    return 0;
}