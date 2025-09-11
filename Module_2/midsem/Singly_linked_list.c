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

void insert_at_first(struct Node** head , int data){

    if(*head == NULL){
        *head = createnode(data);
        return;
    }
    struct Node* newnode = createnode(data);
    newnode ->next = *head;
    *head = newnode;
}

void insert_at_end(struct Node** head, int data){
    struct Node* temp = *head;

    if(temp == NULL){
        struct Node* newnode = createnode(data);
        *head = newnode;
    }

    while(temp->next !=NULL){
        temp = temp -> next;
    }
    temp->next = createnode(data);

}

void insert_at_pos(struct Node** head, int data , int loc){
    struct Node* temp = *head;

    if (loc == 0) {
        struct Node* newnode = createnode(data);
        newnode->next = *head;
        *head = newnode;
        return;
    }

    int i =0;
    while(i<loc-1) {

        if(temp == NULL){
            printf("Out of bounds!!");
            return;
        }
        i++;

        temp = temp->next;
    }

    if(temp == NULL){
        printf("Out of bounds!!");
        return;
    }

    struct Node* newnode = createnode(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletion_at_first(struct Node** head){

    struct Node* temp = *head;

    if(temp == NULL){
        return;
    }

    *head = temp ->next;
    free(temp);
}

void deletion_at_end(struct Node** head){

    struct Node* temp = *head;

    if(temp == NULL){
        return;
    }

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    struct Node* temp1 = temp;

    while(temp ->next!=NULL){
        temp1 = temp;
        temp = temp->next;
    }
    temp1 -> next = NULL;
    free(temp);

}

void deletion_at_pos(struct Node** head, int loc){

    struct Node* temp = *head;

    if(temp == NULL){
        printf("EMPTY LIST!! \n");
        return;
    }

    if (loc == 0) {
        *head = temp -> next;
        free(temp);
        return;
    }

    struct Node* prev = temp;

    int i = 0;
    while(i < loc){
        prev = temp;
        temp = temp->next;
        i++;
    }
    if(temp == NULL){
        printf("out of bounds \n");
        return;
    }
    prev -> next = temp -> next;
    free(temp);

}

void search(struct Node** head, int key){
    struct Node* temp = *head;


    int i=0;
    while(temp != NULL){
        if(temp->data == key){
            printf("Found the element %d at index %d",key,i);
            return;
        }
        temp = temp-> next;
        i++;
    }
    printf("element %d does not exist in the list\n",key);

}

void reverse(struct Node** head){
    struct Node* current = *head;
    struct Node* next;
    struct Node* prev = NULL;

    if(current == NULL){
        printf("Empty list\n");
        return;
    }

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}


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

//    deletion_at_pos(&head,2);
//    print(head);

//    search(&head,50);

    reverse(&head);
    print(head);





    return 0;
}