#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createnode(int data){
    struct node* newnode = malloc(sizeof (struct node));
    newnode ->data = data;
    newnode->next =NULL;
    return newnode;
}
//push
void push(struct node** top,int item){
    if(*top == NULL){
        *top = createnode(item);
        return;
    }
    struct node* newnode = createnode(item);
    newnode ->next = *top;
    (*top) = newnode;
}
//pop
void pop(struct node** top){
    if(*top == NULL){
        return;
    }
    struct node* temp = *top;
    (*top) = (*top)->next;
    free(temp);
}
//peek
void peek(struct node** top){
    if(*top == NULL){
        printf("stack is empty!!\n");
        return;
    }
    printf("peeking at %d",(*top)->data);
}
//display
void display(struct node** top){
    if(*top == NULL){
        printf("stack is empty!!\n");
        return;
    }
    struct node* temp = *top;
    while(temp!= NULL){
        printf("%d ->",temp->data);
        temp = temp ->next;
    }
    printf("NULL\n");
}

int main(){
    struct node* top = NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    push(&top,4);
    display(&top);
    pop(&top);
    peek(&top);


}