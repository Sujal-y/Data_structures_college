//bfs

#include <stdio.h>
#include<stdlib.h>
#define MAX 50
struct node {
    int vertex;
    struct node* next;
};

struct node* graph[MAX]; //adjacency list
int visted[MAX];
int n ; //for how many vertices

struct node* create_node(int data) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->vertex = data;
    newnode->next =NULL;
    return newnode;
}

void add_edge(int v1,int v2) {
    struct node* newnode = create_node(v2);
    newnode->next = graph[v1];
    graph[v1] = newnode;

    struct node* newnode2 = create_node(v1);
    newnode2->next = graph[v2];
    graph[v2] = newnode2;

}

void displayGraph() {
    for (int i = 0; i < n; i++) {
        struct node* temp = graph[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next; }
        printf("NULL\n"); }
}

struct qnode {
    int vertex;
    struct qnode* next;
};
struct qnode* create_qnode(int data) {
    struct qnode* newnode = malloc(sizeof(struct qnode));
    newnode->vertex = data;
    newnode->next=NULL;
    return newnode;
}

void enqueue(struct qnode** front, struct qnode** rear, int v) {
    struct qnode* newnode = create_qnode(v);

    if (*front == NULL) {
        *front = newnode;
        *rear = newnode;
    } else {
        (*rear)->next = newnode;
        *rear = newnode;
    }
}

int dequeue(struct qnode** front, struct qnode** rear) {
    if (*front == NULL) {
        return -1; // Return -1 to indicate empty
    }
    struct qnode* temp = *front;
    int first = (*front)->vertex;
    (*front) = (*front)->next ;
    free(temp);
    if (*front == NULL) {
        *rear = NULL;
    }
    return first;
}


void bfs(int v) {
    struct qnode* front = NULL;
    struct qnode* rear =NULL;

    printf("%5d", v);
    visted[v] = 1;
    enqueue(&front,&rear,v);

    //checks for neighbours
    while (front != NULL) {
        int current_vertex = dequeue(&front,&rear);
        struct node *crawler = graph[current_vertex];
        while (crawler != NULL) {
            if (visted[crawler->vertex] == 0) {
                printf("%5d", crawler->vertex);
                visted[crawler->vertex] = 1;
                enqueue(&front,&rear,crawler->vertex);
            }
            crawler = crawler->next;
        }

    }

}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
        visted[i] =0;
    }
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(src, dest); }

    int startVertex =0;
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);
    printf("\nBreadth First Search Traversal:\n");
    bfs(startVertex);


    return 0;}


