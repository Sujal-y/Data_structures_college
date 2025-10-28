// Write a recursive function to:
// i) Create a binary tree
// ii) Print the binary tree (in traversal order, typically level-order)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;

    printf("Enter left child of %d:\n", data);
    newNode->left = createNode();

    printf("Enter right child of %d:\n", data);
    newNode->right = createNode();

    return newNode;
}

// --- Queue for Level-Order ---
struct QNode {
    struct Node* treeNode;
    struct QNode* next;
};

struct Queue {
    struct QNode *front;
    struct QNode *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isQueueEmpty(struct Queue* q) {
    return (q->front == NULL);
}

void enqueue(struct Queue* q, struct Node* treeNode) {
    struct QNode* newNode = (struct QNode*)malloc(sizeof(struct QNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

struct Node* dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }
    struct QNode* temp = q->front;
    struct Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return treeNode;
}
// --- End of Queue ---

void printLevelOrder(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        struct Node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(q, current->left);
        }

        if (current->right != NULL) {
            enqueue(q, current->right);
        }
    }

    free(q);
}

// Recursive function to free memory
void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


int main() {
    printf("--- Create Binary Tree ---\n");

    struct Node* root = createNode();

    printf("\n--- Level-Order Traversal ---\n");
    printLevelOrder(root);
    printf("\n");

    // Clean up memory
    freeTree(root);

    return 0;
}

