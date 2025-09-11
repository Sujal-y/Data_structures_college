#include<stdio.h>
#include<stdlib.h>

struct cnode{
    int data;
    struct cnode* next;
};

struct cnode* createnode(int data){
    struct cnode* newnode =(struct cnode*)malloc(sizeof(struct cnode));
    newnode->data = data;
    newnode -> next = NULL;
    return newnode;
}

void insert_at_first(struct cnode** head , int data){

    if(*head == NULL){
        *head = createnode(data);
        return;
    }
    struct cnode* newnode = createnode(data);
    newnode ->next = *head;
    *head = newnode;
}

void insert_at_end(struct cnode** head, int data){
    struct cnode* temp = *head;

    if(temp == NULL){
        struct cnode* newnode = createnode(data);
        *head = newnode;
    }

    while(temp->next !=NULL){
        temp = temp -> next;
    }
    temp->next = createnode(data);

}

void insert_at_pos(struct cnode** head, int data , int loc){
    struct cnode* temp = *head;

    if (loc == 0) {
        struct cnode* newnode = createnode(data);
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

    struct cnode* newnode = createnode(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletion_at_first(struct cnode** head){

    struct cnode* temp = *head;

    if(temp == NULL){
        return;
    }

    *head = temp ->next;
    free(temp);
}

void deletion_at_end(struct cnode** head){

    struct cnode* temp = *head;

    if(temp == NULL){
        return;
    }

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    struct cnode* temp1 = temp;

    while(temp ->next!=NULL){
        temp1 = temp;
        temp = temp->next;
    }
    temp1 -> next = NULL;
    free(temp);

}

void deletion_at_pos(struct cnode** head, int loc){

    struct cnode* temp = *head;

    if(temp == NULL){
        printf("EMPTY LIST!! \n");
        return;
    }

    if (loc == 0) {
        *head = temp -> next;
        free(temp);
        return;
    }

    struct cnode* prev = temp;

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

void search(struct cnode** head, int key){
    struct cnode* temp = *head;


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

void reverse(struct cnode** head){
    struct cnode* current = *head;
    struct cnode* next;
    struct cnode* prev = NULL;

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


void print(struct cnode* head){
    struct cnode* temp = head;
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
    struct cnode* head = NULL;

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