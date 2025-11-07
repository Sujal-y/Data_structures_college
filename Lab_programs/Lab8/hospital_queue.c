//Create a queue of structures (e.g., queue of patients with name, age, and priority).
#include<stdlib.h>
#include <stdio.h>
#include<string.h>

struct patients
{
    char name[50];
    int age;
    int priority; // 1 to 3 with 3 being highest
};

struct node
{
    struct patients* patient;
    struct node* next;

};


struct node* createnode(char name[50],int age,int priority)
{
    struct node* newnode = malloc(sizeof(struct node));
    struct patients* new_record = malloc(sizeof(struct patients));
    strcpy(new_record->name,name);
    new_record->age = age;
    new_record->priority = priority;
    newnode->patient = new_record;
    newnode->next =NULL;
    return newnode;
}

void enqueue(struct node** head,char name[50],int age,int priority)
{
    struct node* newnode = createnode(name,age,priority);

    if (*head == NULL || (*head)->patient->priority < priority)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    struct node* temp = *head;

    while (temp->next != NULL && temp->next->patient->priority >= priority)
    {
        temp = temp->next;
    }


    newnode->next = temp->next;
    temp->next = newnode;

}

void dequeue(struct node** head)
{
    if (*head == NULL)
    {
        return;
    }

    struct node* temp = *head;
    (*head) = (*head)->next;
    free(temp->patient);
    free(temp);
}

void display(struct node* head)
{
    if (head == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("\n--- Patient Queue (Front to Back) ---\n");
    struct node* temp = head;
    while (temp != NULL)
    {
        // Print patient details
        printf("  Priority: %d | Name: %s | Age: %d\n",
               temp->patient->priority,
               temp->patient->name,
               temp->patient->age);
        temp = temp->next; // Move to the next node
    }
    printf("--- End of Queue ---\n");
}

int main()
{
    struct node* head = NULL; // Start with an empty queue

    // Test enqueuing. We add them out of order to test the priority logic.
    enqueue(&head, "Bob (Low Prio)", 45, 1);
    enqueue(&head, "Alice (High Prio)", 30, 3);
    enqueue(&head, "Charlie (Mid Prio)", 22, 2);
    enqueue(&head, "David (High Prio)", 68, 3);

    // Display the fully sorted queue
    // Expected order: Alice (3), David (3), Charlie (2), Bob (1)
    display(head);


    dequeue(&head); // Dequeues Alice (Priority 3)
    dequeue(&head); // Dequeues David (Priority 3)


    // Expected order: Charlie (2), Bob (1)
    display(head);


    enqueue(&head, "Eve (Mid Prio)", 50, 2);

    // Expected order: Charlie (2), Eve (2), Bob (1)
    display(head);

    // Dequeue all remaining patients
    dequeue(&head); // Dequeues Charlie (2)
    dequeue(&head); // Dequeues Eve (2)
    dequeue(&head); // Dequeues Bob (1)

    display(head);


    dequeue(&head);

    return 0;
}



