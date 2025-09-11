#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createnode(int data){
    struct Node* newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode -> next = NULL;
    newnode->prev =NULL;
    return newnode;
}

void insert_at_first(struct Node** head , int data){

    if(*head == NULL){
        *head = createnode(data);
        return;
    }
    struct Node* temp = *head;
    struct Node* newnode = createnode(data);
    newnode ->next = *head;
    newnode->prev = NULL;
    temp ->prev = newnode;
    *head = newnode;
}

void insert_at_end(struct Node** head, int data){
    struct Node* temp = *head;

    if(temp == NULL){
        struct Node* newnode = createnode(data);
        *head = newnode;
        return;
    }

    while(temp->next !=NULL){
        temp = temp -> next;
    }

    struct Node* newnode = createnode(data);
    temp->next = newnode;
    newnode ->prev = temp;


}

void insert_at_pos(struct Node** head, int data , int loc){
    struct Node* temp = *head;

    if (loc == 0) {
        struct Node* newnode = createnode(data);
        newnode->next = *head;
        newnode ->prev =NULL;
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
    newnode->prev = temp;
    temp ->next = newnode;

    if(newnode ->next != NULL){
        temp = temp ->next; //now temp is at new node
        temp = temp-> next;
        temp->prev =newnode;
    }

}

void deletion_at_first(struct Node** head){

    struct Node* temp = *head;

    if(temp == NULL){
        return;
    }
    if(temp->next != NULL){
        *head = temp ->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }
    free(temp);
    *head = NULL;
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

    while(temp ->next != NULL){
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
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    int i =0;
    while(i<(loc-1)){
        if(temp == NULL){
            printf("Position is out of bounds");
            return;
        }
        temp = temp->next;
        i++;

    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position is out of bounds!\n");
        return;
    }

    struct Node* node_deleted = temp->next;
    temp -> next = node_deleted->next;

    if (node_deleted->next != NULL) {
        node_deleted->next->prev = temp;
    }

    free(node_deleted);
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

void print(struct Node* head){
    struct Node* temp = head;
    printf("The doubly linked list:- \n");

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

void print_reverse(struct Node* head){
    struct Node* temp = head;
    printf("The reversed doubly linked list:- \n");

    if(temp == NULL){
        printf("NULL\n");
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    while(temp != NULL){
        printf("%d -> ",temp -> data);
        temp = temp->prev;
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
    

//    insert_at_end(&head,10);
//    print(head);
//    insert_at_end(&head,20);
//    print(head);

    insert_at_end(&head,10);
    insert_at_end(&head,20);
    insert_at_end(&head,30);
    insert_at_end(&head,40);
    insert_at_end(&head,50);
    print(head);

//    insert_at_pos(&head,25,2);
//    print(head);
//    print_reverse(head);

//    deletion_at_first(&head);
//    print(head);
//    print_reverse(head);
//
//    deletion_at_end(&head);
//    print(head);
//    print_reverse(head);

//    deletion_at_pos(&head,2);
//    print(head);
//    print_reverse(head);

//    search(&head,50);

//    print_reverse(head);






    return 0;
}