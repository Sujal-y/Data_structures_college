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
//push(item) : places item on top the stack
void push(struct node** top,int item){
    //case: stack is empty
    if(*top == NULL){
        *top = createnode(item);
        return;
    }
    struct node* newnode = createnode(item);
    newnode ->next = *top; //new item is pointing to top
    (*top) = newnode; // the top is changed to the new item
}
//pop : removes the top item from the stack
void pop(struct node** top){
    //case: stack is empty
    if(*top == NULL){
        printf("Nothing to pop\n");
        return;
    }
    struct node* temp = *top;
    (*top) = (*top)->next; //top is reassigned to next pointer
    free(temp); //old top saved using temp is freed
}
//peek : prints the top element
void peek(struct node** top){
    //case: the stack is empty
    if(*top == NULL){
        printf("stack is empty!!\n");
        return;
    }
    printf("peeking at %d",(*top)->data);
}
//display : displays the stack
void display(struct node** top){
    //case: the stack is empty
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