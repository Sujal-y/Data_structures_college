//
// Created by Sujal Y on 26/09/2025.
//
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createnode(int value) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (!newnode) {
        printf("memory allocation failed");
        exit(1);
    }
    newnode->data= value;
    newnode -> next = newnode ->prev = NULL;
    return newnode;
}

void insert_at_first(struct node** head,int value) {
    struct node* newnode = createnode(value);
    newnode->next = *head;
    (*head) ->prev = newnode;
    *head = newnode;
}
void insertatend(struct node** head,struct node**tail, int value ) {
    struct node* newnode = createnode(value);
    if (*head==NULL) {
        *head=newnode;
        *tail = newnode;
        return;
    }
    newnode->next = NULL;
    newnode ->prev = *tail;
    (*tail)->next = newnode;
    *tail = newnode;
}

void deleteatfirst(struct node** head) {
    if (*head ==NULL) {
        printf("list is empty");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteatend(struct node** tail) {
    if (*tail ==NULL) {
        printf("list is empty");
        return;
    }
    struct node* temp = *tail;
    (*tail)->prev->next = NULL;
    *tail = temp->prev;
    free(temp);
}
void display(struct node* head) {
    if (head == NULL) {
        printf("list is empty");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

void insertatpos(struct node** head, int pos, int value) {
    if (pos==1) {
        insert_at_first(&head, value);
        return;
    }
    struct node* temp = *head;
    int i=1;
    while (temp!=NULL && i<pos) {
        temp =  temp->next;
        i++;
    }
    if (temp==NULL) {
        printf("position out of range");
        return;
    }
    struct node* newnode = createnode(value);
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp-> next= newnode;
    newnode->prev = temp;

}






int  main() {
    struct node* head=NULL;
    struct node* tail=NULL;
    int n,value,pos;
    do{
        printf("menu:\n");
        printf("enter: \n 1.insert at first \n 2.insert at end\n 3.delete at first \n 4.delete at end \n 5.display list");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("enter the value for the node");
                scanf("%d", &value);
                insert_at_first(&head,value);
                break;
            case 2:
                printf("enter the value for the node");
                scanf("%d", &value);
                insertatend(&head,&tail,value);
                break;
            case 3:
                deleteatfirst(&head);
                break;
            case 4 :
                deleteatend(&tail);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("enter data and position");
                scanf("%d", &value);
                scanf("%d",&pos);
                insertatpos(&head, pos,value);
                break;

            case 0:
                printf("exiting..");
                break;

        }
    }while (n!=0);

    return 0;
}