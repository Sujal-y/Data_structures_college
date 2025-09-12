#include<stdio.h>
#define MAX 5
int top =-1; //this is used for finding the current top element
int stack[MAX];

//push(item) : places item on top the stack
void push(int item) {
    //case: the stack is full and cannot add item to stack
    if (top == MAX-1) {
        printf("stack overflow");
        return;
    }
    //adds item to stack and increments top by 1
    stack[++top] = item;
    printf("%d pushed to stack.\n", item);
}

//pop : removes the top item from the stack
void pop() {
    //case: the stack is empty
    if (top == -1) {
        printf("stack empty\n");
        return;
    }
    //decrements the top , the old value is not deleted like in linked list
    printf("%d popped\n",stack[top]);
    --top;

}
//peek : prints the top element
void peek() {
    //case: the stack is empty
    if (top == -1) {
        printf("stack empty\n");
        return;
    }
    printf("top element:- %d",stack[top]);
}

//isempty : checks weather stack is empty
void isempty() {
    if (top == -1) {
        printf("Is empty\n");
    }
    else {
        printf("Its not empty\n");
    }
}

//display : displays the stack
void display() {
    //case: the stack is empty
    if (top==-1) {
        printf("Empty stack\n");
    }

    printf("top <- Bottom\n");
    for (int i = top;i >= 0;i--) {
        printf("%d <-",stack[i]);
    }
    printf("\n");
}

int main() {
    display();
    push(4);
    push(5);
    display();
    pop();
    display();
    isempty();
    peek();

}