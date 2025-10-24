#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *next;
};

// Global pointers to the first and last nodes
struct node *first = NULL;
struct node *last = NULL;

/**
 * @brief Inserts a new node at the end of the circular list.
 * * @param value The integer value to be inserted.
 */
void insertEnd(int value) {
    // 1. Create a new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    // 2. Check if the list is empty
    if (first == NULL) {
        first = newNode;
        last = newNode;
        last->next = first; // Point back to itself to make it circular
    } else {
        // 3. If not empty, link the current last node to the new node
        last->next = newNode;
        // 4. Update the last pointer to the new node
        last = newNode;
        // 5. Point the new last node back to the first node
        last->next = first;
    }
    printf("Inserted %d at the end.\n", value);
}

/**
 * @brief Inserts a new node at the end of the circular list.
 * This function is functionally identical to insertEnd.
 * @param value The integer value to be inserted.
 */
void insertAtLast(int value) {
    // 1. Create a new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    // 2. Check if the list is empty
    if (first == NULL) {
        first = newNode;
        last = newNode;
        last->next = first; // Point back to itself to make it circular
    } else {
        // 3. If not empty, link the current last node to the new node
        last->next = newNode;
        // 4. Update the last pointer to the new node
        last = newNode;
        // 5. Point the new last node back to the first node
        last->next = first;
    }
    printf("Inserted %d using insertAtLast.\n", value);
}


/**
 * @brief Displays all the elements in the circular linked list.
 */
void display() {
    // Check if the list is empty
    if (first == NULL) {
        printf("List is empty.\n\n");
        return;
    }

    struct node *temp = first;
    printf("List: ");
    // Use a do-while loop to traverse the circular list
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first); // Loop until we reach the start again

    printf("(head: %d)\n\n", first->data);
}

// Main function to drive the program
int main() {
    // Initially, the list is empty
    display();

    // Insert elements and display the list after each insertion
    insertEnd(10);
    display();

    insertEnd(20);
    display();

    insertEnd(30);
    display();

    // Demonstrate the new insertAtLast function
    insertAtLast(40);
    display();

    return 0;
}

