//Depth First Search
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

//ppt add edge
// void add_edge(int v1,int v2) {
//     struct node* newnode = create_node(v2);
//     newnode->next = graph[v1];
//     graph[v1] = newnode;
//
//     struct node* newnode2 = create_node(v1);
//     newnode2->next = graph[v2];
//     graph[v2] = newnode2;
//
// }

//my own method
void add_edge(int v1,int v2) {
    if (graph[v1]==NULL) {
        struct node* temp = create_node(v2);
        graph[v1] = temp;
    }
    else {
        struct node* temp = graph[v1];
        while (temp->next !=NULL){temp = temp->next;}
        temp->next = create_node(v2);
    }
    //for undirected graph
    if (graph[v2]==NULL) {
        struct node* temp = create_node(v1);
        graph[v2] = temp;

    }
    else {
        struct node* temp2 = graph[v2];
        while (temp2->next !=NULL){temp2 = temp2->next;}
        temp2->next = create_node(v1);
    }

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
void dfs(int v) {
    struct node* crawler = graph[v];
    visted[v] =1;
    printf("%d   ",v);

   while (crawler!=NULL) {
       if (visted[crawler->vertex] == 0) {
           dfs(crawler->vertex);
       }
       crawler = crawler->next;
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
        add_edge(src, dest);
    }
    int startVertex =0;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("\nDepth First Search Traversal:\n");
    dfs(startVertex);


    return 0;}


