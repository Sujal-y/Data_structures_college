#include<stdio.h>
#include<stdlib.h>

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

// Function to insert a new element at the beginning of the singly linked list
void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new element at the end of the singly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
//

//Insert at pos
void insertAtPos(struct Node** head, int data,int pos) {
    if (pos == 0) {
        insertAtFirst(head, data);
        return;
    }

    // Find the node at the position *before* the target (pos - 1).
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    // 3. Check if the position was valid. If temp is NULL, it means the
    // position was out of the list's bounds.
    if (temp == NULL) {
        printf("Position %d is out of range.\n", pos);
        return;
    }

    // 4. Now that we are at the correct node (pos - 1), create the new node and link it.
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;

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

    // insertAtFirst(&head, 10);
    // printf("Linked list after inserting the node:10 at the beginning \n");
    // print(head);
    //
    // insertAtEnd(&head, 20);
    // printf("Linked list after 20\n");
    // print(head);

    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);
    insertAtEnd(&head,50);

    print(head);
    insertAtPos(&head,40,3);
    insertAtPos(&head,35,3);
    print(head);









    return 0;
}