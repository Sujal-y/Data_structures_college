#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Need this for isalnum()

struct node
{
    char data;
    struct node* next;
};

struct node* createnode(char data)
{
    struct node* newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// --- Modified pop to return the data ---
char pop(struct node** head)
{
    if (*head == NULL)
    {
        return '\0';
    }

    struct node* temp = *head;
    char popped_data = temp->data;
    *head = (*head)->next;
    free(temp);

    return popped_data;
}

void push(struct node** head, char c)
{
    struct node* temp = createnode(c);
    temp->next = *head;
    *head = temp;
}

// --- Added stackTop (peek) function ---
char stackTop(struct node* head)
{
    if (head == NULL)
    {
        return '\0'; // Return null char if stack is empty
    }
    return head->data;
}


void display(struct node* head)
{
    if (head == NULL)
    {
        printf("empty stack\n");
        return;
    }
    printf("Top -> Bottom \n");

    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%c ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

int isRightAssociative(char c) {
    return c == '^';
}

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1; // For non-operators
}


// --- Completed infix_postfix function ---
void infix_postfix(char* s, char* postfix)
{
    struct node* head = NULL; // This is our operator stack
    const int infix_length = strlen(s);
    int j = 0; // Index for the postfix string

    for (int i = 0; i < infix_length; i++)
    {
        char c = s[i];

        // If operand, add to postfix string
        if (isalpha(c))
        {
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(')
        {
            push(&head, c);
        }
        // If ')', pop from stack to postfix until '('
        else if (c == ')')
        {
            while (stackTop(head) != '\0' && stackTop(head) != '(')
            {
                postfix[j++] = pop(&head);
            }
            pop(&head); // Pop the '('
        }
        // If operator
        else
        {
            // Pop operators with higher or equal precedence
            while (stackTop(head) != '\0' && stackTop(head) != '(' && (prec(stackTop(head)) > prec(c) ||
                    (prec(stackTop(head)) == prec(c) && !isRightAssociative(c))))
            {
                postfix[j++] = pop(&head);
            }
            // Push the current operator
            push(&head, c);
        }
    }

    // Pop all remaining operators from stack
    while (stackTop(head) != '\0')
    {
        postfix[j++] = pop(&head);
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}

// --- Corrected main ---
int main()
{
    printf("Enter the infix string: ");
    char infix[50];
    scanf("%s", infix);

    char postfix[50]; // Create an empty string to hold the result

    // Pass both strings to the function
    infix_postfix(infix, postfix);

    printf("The postfix expression is: %s \n", postfix);

    return 0;
}