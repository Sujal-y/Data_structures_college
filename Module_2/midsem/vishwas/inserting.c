#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create(int value){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void InBeg_tail(struct node** tail,int value){
    struct node* newNode=create(value);
    if(*tail==NULL){
        *tail=newNode;
        newNode->next=newNode;
        return;
    }

    newNode->next=(*tail)->next;
    (*tail)->next=newNode;
}

void InEnd_tail(struct node** tail, int value){
    struct node* newNode=create(value);
    if(*tail==NULL){
        *tail=newNode;
        newNode->next=newNode;
        return;
    }

    newNode->next=(*tail)->next;
    (*tail)->next=newNode;
    *tail=newNode;
}

void InBeg_head(struct node** head,int value){
    struct node* newNode=create(value);
    if(*head==NULL){
        *head=newNode;
        newNode->next=newNode;
        return;
    }
    struct node* temp=*head;
    while(temp->next!=*head){
        temp=temp->next;
    }
    newNode->next=*head;
    temp->next=newNode;
    *head=newNode;
}

void InEnd_head(struct node** head,int value){
    struct node* newNode=create(value);
    if(*head==NULL){
        *head=newNode;
        newNode->next=newNode;
        return;
    }
    struct node* temp=*head;
    while(temp->next!=*head){
        temp=temp->next;
    }
    newNode->next=*head;
    temp->next=newNode;
}

void display(struct node* head){
    if(head==NULL){
        printf("Empty list");
        return;
    }
    struct node* temp=head;
    do{
        printf(" %d->",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("Back to head\n");
}

int main(){
    struct node* head=NULL;
    struct node* tail=NULL;

    printf("===Using tail pointer===");
    InBeg_tail(&tail,10);
    InEnd_tail(&tail,20);
    display(tail->next);

    printf("===Using head pointer===");
    InBeg_head(&head,30);
    InEnd_head(&head,40);
    display(head);

    return 0;
}