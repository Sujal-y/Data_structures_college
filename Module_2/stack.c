#include<stdlib.h>
#include <stdio.h>
//3+5*(5/5)-2^2
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element in stack
void push(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to pop an element
void pop(struct Node** head) {
    struct Node* temp = *head;
    temp = temp -> next;
    *head = temp;

}

//Function to print the linked list
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    push(&head,9);
    push(&head,2);
    push(&head,6);
    print(head);
    pop(&head);
    print(head);
    printf("%d",3+5*(5/5)-2^2);


    return 0;
}
