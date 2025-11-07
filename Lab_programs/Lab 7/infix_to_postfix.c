//infix to postfix

#include <ctype.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
    char data;
    struct node* next;

};

char stack_top(struct node** head)
{
    if (*head == NULL)
    {
        return '\0';
    }
    const char element = (*head)->data;
    return element;

}

struct node* createnode(char data)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void push(struct node** head,char data)
{
    if ((*head) == NULL)
    {
        *head =  createnode(data);
        return;
    }
    struct node* temp = createnode(data);
    temp->next = *(head);
    *head = temp;
}

char pop(struct node** head)
{
    if (*head == NULL)
    {
        return '\0';
    }
    char element = (*head)->data;
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);

    return element;
}

int precedence(const char token)
{
    if (token == '^')
    {
        return 3;
    }
    else if (token == '/' || token == '*')
    {
        return 2;
    }
    else if (token == '+'|| token =='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int isRightAssociative(const char token)
{
    if (token == '^')
    {
        return 1;
    }
    return 0;
}

void infix_to_postfix(char infix[],char postfix[])
{
    int length = strlen(infix);
    int j =0 ; //for postfix indexing

    struct node* head = NULL;

    for (int i=0;i<length;i++)
    {
        char token = infix[i];
        if (isalpha(token)) // change to isalnum for numbers
        {
            postfix[j++] = token;
        }
        else if (token == '(')
        {
            push(&head,token);
        }
        else if (token == ')')
        {
            while (stack_top(&head)!= '\0' && stack_top(&head) != '(')
            {
                postfix[j++] = pop(&head);
            }
            pop(&head);
        }
        else
        {
            while (stack_top(&head) != '\0' && stack_top(&head)!='(' &&
                (precedence(stack_top(&head))>precedence(token) ||
                    (precedence(stack_top(&head))==precedence(token))&&!isRightAssociative(token)))
            {
                postfix[j++] = pop(&head);

            }
            push(&head,token);
        }


    }

    while (stack_top(&head) != '\0')
    {
        postfix[j++] = pop(&head);
    }

    postfix[j] = '\0';

}


int main()
{
    char infix[50];
    printf("Enter the infix string:");
    scanf("%s",infix);

    char postfix[50];
    infix_to_postfix(infix,postfix);
    printf("The postfix expression is: %s \n",postfix);
    return 0;
}