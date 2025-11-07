#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// --- A NEW Stack for Integers ---
// We need a stack for 'int' results, not 'char'.
struct int_node {
    int data;
    struct int_node* next;
};

// Creates a new node for the integer stack
struct int_node* int_createnode(int data) {
    struct int_node* newnode = (struct int_node*)malloc(sizeof(struct int_node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Pushes an integer onto the stack
void int_push(struct int_node** head, int data) {
    struct int_node* newnode = int_createnode(data);
    newnode->next = *head;
    *head = newnode;
}

// Pops an integer from the stack
int int_pop(struct int_node** head) {
    if (*head == NULL) {
        printf("Stack underflow! Invalid postfix expression.\n");
        return 0; // Return 0 or exit
    }
    struct int_node* temp = *head;
    int popped_data = temp->data;
    *head = (*head)->next;
    free(temp);
    return popped_data;
}

// --- Postfix Evaluation Function ---
int postfix_evaluation(char postfix[]) {
    int length = strlen(postfix);
    struct int_node* head = NULL; // Use the integer stack

    for (int i = 0; i < length; i++) {
        char token = postfix[i];

        // 1. If it's a digit (operand)
        if (isdigit(token)) {
            // Convert char digit to int value and push
            int_push(&head, token - '0');
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^') {
            // --- CRITICAL FIX: Pop in correct order ---
            // First pop is the SECOND operand (val2)
            int val2 = int_pop(&head);
            int val1 = int_pop(&head);
            int result;

            switch (token) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    if (val2 == 0) {
                        printf("Error: Division by zero.\n");
                        exit(1);
                    }
                    result = val1 / val2;
                    break;
                case '^':
                    result = (int)pow(val1, val2);
                    break;
            }
            int_push(&head, result);
        }
    }
    return int_pop(&head);
}

// --- Main function to test the evaluation ---
int main() {
    // Example: (8+2)*5 / (4-2) = 10 * 5 / 2 = 25
    char postfix1[] = "82+5*42-/"; 
    int result1 = postfix_evaluation(postfix1);
    printf("Postfix Expression: %s\n", postfix1);
    printf("Result: %d\n", result1);
    printf("\n");

    // Example: 2^3 + 5*4 = 8 + 20 = 28
    char postfix2[] = "23^54*+"; 
    int result2 = postfix_evaluation(postfix2);
    printf("Postfix Expression: %s\n", postfix2);
    printf("Result: %d\n", result2);
    printf("\n");
    
    // Example from your previous code
    char infix[50];
    printf("Enter an infix string with single digits (e.g., 5*(6+2)/4): ");
    scanf("%s", infix);
    
    // NOTE: This assumes you have your (correct) infix_to_postfix
    // function also in this file. For this example, I'll use a placeholder.
    // infix_to_postfix(infix, postfix);
    // printf("Postfix: %s\n", postfix);
    // int result3 = postfix_evaluation(postfix);
    // printf("Result: %d\n", result3);

    return 0;
}