#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;
struct node* tail=NULL;

struct node* create(int value){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void inEnd(int value){
    struct node* newNode=create(value);
    if(head==NULL){
        head=tail=newNode;
        newNode->next=newNode;
        return;
    }else{
        newNode->next=tail->next;
        tail->next=newNode;
        tail=newNode;
    }
}

void delBeg_tail(){
    if(tail==NULL){
        printf("Empty list\n");
        return;
    }else if(tail==tail->next){
        free(tail);
        head=tail=NULL;
    }else{
        struct node* temp;
        temp=tail->next;
        tail->next=temp->next;
        free(temp);
    }
}

void delEnd_tail(){
    if(tail==NULL){
        printf("Empty list\n");
        return;
    }else if(tail==tail->next){
        free(tail);
        head=tail=NULL;
    }else{
        struct node* temp=tail;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=tail->next;
        free(tail);
        tail=temp;
    }
}

void delBeg_head(){
    if(head==NULL){
        printf("Empty list\n");
        return;
    }else if(head->next==head){
        free(head);
        head=tail=NULL;
    }else{
        struct node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=head->next;
        free(head);
        head=temp->next;
    }
}

void delEnd_head(){
    if(head==NULL){
        printf("Empty list\n");
        return;
    }else if(head==head->next){
        free(head);
        head=tail=NULL;
    }else{
        struct node* temp=head;
        while(temp->next->next!=head){
            temp=temp->next;
        }
        struct node* del=temp->next;
        temp->next=head;
        free(del);
        tail=temp;
    }
}

void display(){
    if(head==NULL){
        printf("Empty list\n");
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
    inEnd(10);
    inEnd(20);
    inEnd(30);
    inEnd(40);
    inEnd(50);
    printf("Original list:");
    display();

    printf("===Tail operations===\n");
    delBeg_tail();
    delEnd_tail();
    display();

    printf("===Head operations===\n");
    delBeg_head();
    delEnd_head();
    display();

    return 0;
}