#include<stdio.h>
#define MAX 5
int top =-1;
int stack[MAX];
//push(item)
void push(int item) {
    if (top == MAX-1) {
        printf("stack overflow");
        return;
    }
    stack[++top] = item;
    printf("%d pushed to stack.\n", item);
}

//pop
void pop() {
    if (top == -1) {
        printf("stack empty\n");
        return;
    }
    --top;
}
//peek
void peek() {
    if (top == -1) {
        printf("stack empty\n");
        return;
    }
    printf("top element:- %d",stack[top]);
}

//isempty
void isempty() {
    if (top == -1) {
        printf("Is empty\n");
    }
    else {
        printf("Its not empty\n");
    }
}

//display
void display() {
    if (top==-1) {
        printf("Empty stack\n");
    }
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