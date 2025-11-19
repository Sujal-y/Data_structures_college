//adjacency list

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
    newnode->next = graph[v2];
    graph[v2] = newnode;

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

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(src, dest); }

    printf("\nAdjacency List Representation:\n");
    displayGraph();
    return 0;}


