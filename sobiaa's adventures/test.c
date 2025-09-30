#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the student record
struct Node {
    char* name;
    int roll_no;
    int marks;
    struct Node* next;
};

// Creates a new student record node
struct Node* createnode(char* name, int roll, int mark) {
    // Allocate memory for the new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Allocate memory for the name and copy it
    newnode->name = (char*)malloc(strlen(name) + 1);
    if (newnode->name == NULL) {
        printf("Memory allocation failed for name!\n");
        exit(1);
    }
    strcpy(newnode->name, name);

    newnode->roll_no = roll;
    newnode->marks = mark;
    newnode->next = NULL;
    return newnode;
}

// Inserts a node at the end of the list
void insert_at_end(struct Node** head, char* name, int roll, int mark) {
    struct Node* newnode = createnode(name, roll, mark);

    // If the list is empty, the new node becomes the head
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node at the end
    temp->next = newnode;
}

// Deletes a node by roll number
void delete_node(struct Node** head, int roll) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the list is empty
    if (temp == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    // If the head node itself holds the roll number to be deleted
    if (temp != NULL && temp->roll_no == roll) {
        *head = temp->next; // Change head
        free(temp->name);   // Free the allocated name string
        free(temp);         // Free the node
        printf("Record with Roll No %d deleted.\n", roll);
        return;
    }

    // Search for the roll number, keeping track of the previous node
    while (temp != NULL && temp->roll_no != roll) {
        prev = temp;
        temp = temp->next;
    }

    // If roll number was not present in the list
    if (temp == NULL) {
        printf("Record with Roll No %d not found.\n", roll);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp->name); // Free the allocated name string
    free(temp);       // Free the node
    printf("Record with Roll No %d deleted.\n", roll);
}


// Prints the entire singly linked list
void print(struct Node* head) {
    struct Node* temp = head;
    printf("\n--- Student Records ---\n");

    if (temp == NULL) {
        printf("No records found.\n");
        return;
    }

    while (temp != NULL) {
        printf("--------------------\n");
        printf("Name:        %s\n", (temp->name));
        printf("Roll Number: %d\n", (temp->roll_no));
        printf("Marks:       %d\n", (temp->marks));
        printf("--------------------\n");
        temp = temp->next;
    }
}

// Frees all the memory allocated for the list
void free_list(struct Node** head) {
    struct Node* current = *head;
    struct Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current->name); // Free the name string first
        free(current);       // Then free the node itself
        current = next_node;
    }
    *head = NULL; // Set head to NULL to indicate an empty list
}

int main() {
    struct Node* head = NULL;
    char name[50];
    int roll, marks, choice;

    while (1) {
        // Display menu
        printf("\n--- MENU ---\n");
        printf("1. Add a student record\n");
        printf("2. Display all records\n");
        printf("3. Delete a student record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Check if input is an integer
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name); // Note: this reads a single word for the name
                printf("Enter Roll Number: ");
                scanf("%d", &roll);
                printf("Enter Marks: ");
                scanf("%d", &marks);
                insert_at_end(&head, name, roll, marks);
                printf("Record added successfully!\n");
                break;

            case 2:
                print(head);
                break;

            case 3:
                printf("Enter Roll Number to delete: ");
                scanf("%d", &roll);
                delete_node(&head, roll);
                break;

            case 4:
                printf("Exiting program. Freeing memory...\n");
                free_list(&head);
                return 0; // Exit the program

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}