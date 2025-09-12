#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createnode(int data){
    struct Node* newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode -> next = NULL;
    return newnode;
}
//inserting a node in the beginning using head
void insert_at_first(struct Node** head , int data){

    //case: if the list is empty
    if(*head == NULL){
        *head = createnode(data);
        return;
    }
    struct Node* newnode = createnode(data);
    newnode ->next = *head; //newnode points to towards previous head
    *head = newnode;//head is pointed to newnode
}

//inserting a node in the end using head
void insert_at_end(struct Node** head, int data){
    struct Node* temp = *head;

    //case: if the list is empty
    if(temp == NULL){
        struct Node* newnode = createnode(data);
        *head = newnode;
        return;
    }

    //traverses until the last node which points to NULL
    while(temp->next !=NULL){
        temp = temp -> next;
    }
    temp->next = createnode(data);

}

//inserting a node in the pos using head
void insert_at_pos(struct Node** head, int data , int loc){
    struct Node* temp = *head;

    //case: inserting at first position
    if (loc == 0) {
        struct Node* newnode = createnode(data);
        newnode->next = *head;
        *head = newnode;
        return;
    }

    //traverses through the linked list until the node before you want to insert
    int i =0;
    while(i<loc-1) {

        //case: if position is outside the last node
        if(temp == NULL){
            printf("Out of bounds!!");
            return;
        }
        i++;

        temp = temp->next;
    }

    //Check again after the loop in case the target position is right after the last node
    if(temp == NULL){
        printf("Out of bounds!!");
        return;
    }

    struct Node* newnode = createnode(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

//deletion of a node in the beginning using head
void deletion_at_first(struct Node** head){

    struct Node* temp = *head;

    //case: empty list
    if(temp == NULL){
        return;
    }

    *head = temp ->next;
    free(temp);
}

//deletion of a node in the end using head
void deletion_at_end(struct Node** head){

    struct Node* temp = *head;

    //case: list is empty
    if(temp == NULL){
        return;
    }

    //case: the list has only one node
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    //stores the node before the last node
    struct Node* prev_temp = temp;

    //traverses temp to the last node
    while(temp ->next!=NULL){
        prev_temp = temp;
        temp = temp->next;
    }
    prev_temp -> next = NULL;
    free(temp);

}

//deletion of a node in a position using head
void deletion_at_pos(struct Node** head, int loc){

    struct Node* temp = *head;

    //case: empty list
    if(temp == NULL){
        printf("EMPTY LIST!! \n");
        return;
    }

    //case : deleting first node
    if (loc == 0) {
        *head = temp -> next;
        free(temp);
        return;
    }

    struct Node* prev_temp = temp;

    //traverses temp to the node to be deleted
    int i = 0;
    while(i < loc){
        prev_temp = temp;
        temp = temp->next;
        i++;
    }
    //if temp is past the end of the list
    if(temp == NULL){
        printf("out of bounds \n");
        return;
    }
    prev_temp -> next = temp -> next;
    free(temp);

}

//searching an element in singly linked list
void search(struct Node** head, int key){
    struct Node* temp = *head;

    //traverses temp to the last node
    int i=0;
    while(temp != NULL){
        //if element found it will end the function using return
        if(temp->data == key){
            printf("Found the element %d at index %d",key,i);
            return;
        }
        temp = temp-> next;
        i++;
    }
    printf("element %d does not exist in the list\n",key);

}

//reverses an array
void reverse(struct Node** head){
    struct Node* current = *head;
    struct Node* next;
    struct Node* prev = NULL;

    //case : the list is empty
    if(current == NULL){
        printf("Empty list\n");
        return;
    }


    while(current != NULL){
        next = current->next; // saves the next node address
        current->next = prev; // changes current node to previous node address
        prev = current; // updates previous address as current for the next node
        current = next; //current node is switched to next node
    }

    //the head is changed to the tail of the original list
    *head = prev;
}

//prints the singly linked list
void print(struct Node* head){
    struct Node* temp = head;
    printf("The singly linked list:- \n");

    if(temp == NULL){
        printf("NULL\n");
        return;
    }

    while(temp != NULL){
        printf("%d -> ",(temp ->data));
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;

//    print(head);
//    insert_at_first(&head,5);
//    print(head);
//    insert_at_first(&head,2);
//    print(head);
//
//    insert_at_end(&head,10);
//    print(head);
//
//    insert_at_pos(&head,88,4);
//    print(head);

    insert_at_first(&head,10);
    insert_at_end(&head,20);
    insert_at_end(&head,30);
    insert_at_end(&head,40);
    insert_at_end(&head,50);
    print(head);

//    deletion_at_first(&head);
//    print(head);
//
//    deletion_at_end(&head);
//    print(head);

//    deletion_at_pos(&head,5);
//    print(head);

//    search(&head,50);

//    reverse(&head);
//    print(head);





    return 0;
}