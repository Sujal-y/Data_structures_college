// Consider the expression: ({[a + b] * (c - d)} / e)
// Explain how your stack-based algorithm would process this expression to
// determine its validity. Provide a step-by-step trace of the stack's state (elements
// pushed/popped) for each character encountered. Your explanation should clearly
// demonstrate how the LIFO principle ensures correct pairing of opening and closing
// delimiters.
// Constraints:
// The input expression will only contain alphanumeric characters, operators, and the
// delimiters (, ), {, }, [, ].
// You should handle cases of mismatched delimiters (e.g., {[}), unclosed delimiters
// (e.g., ({)), and extra closing delimiters (e.g., ())).
// Your implementation should return True if the expression is valid and False
// otherwise

/*
 *ANSWER: writen it in text
*Initialize an empty stack.
    1.Scan each character in the expression:
         If it's an opening delimiter ((, {, [), push it onto the stack.
         If it's a closing delimiter (),},]):
         If the stack is empty → invalid (extra closing delimiter).
         Otherwise, pop the top element and check if it matches the closing delimiter.
    2.After scanning, if the stack is not empty → invalid (unclosed delimiters).
    3.If all delimiters are matched correctly → valid.
Initialize an empty stack.
	1.Scan each character in the expression:
	 	If it's an opening delimiter ((, {, [), push it onto the stack.
	 	If it's a closing delimiter (),},]):
	 	If the stack is empty → invalid (extra closing delimiter).
	 	Otherwise, pop the top element and check if it matches the closing delimiter.
	2.After scanning, if the stack is not empty → invalid (unclosed delimiters).
	3.If all delimiters are matched correctly → valid.
•	Error Type: Mismatched delimiters
•	What happens: The algorithm pushes (, {, and [ onto the stack. When it encounters }, it expects to match with {, but the top of the stack is [. This mismatch violates the correct pairing rule.
•	Result: Invalid expression due to incorrect nesting.

2. Expression: ({[a + b]
•	Error Type: Unclosed delimiters
•	What happens: The stack receives (, {, and [; then ] matches and pops [. However, { and ( remain unclosed at the end of the expression.
•	Result: Invalid expression because the stack is not empty after processing.

3. Expression: ({[a + b])}
•	Error Type: Mismatched delimiters
•	What happens: The stack pushes (, {, and [; ] matches and pops [. Then it encounters ) but the top of the stack is {, not (. This is a mismatch.
•	Result: Invalid expression due to incorrect closing order.

RESULT-
Since all delimiters were matched correctly and the stack is empty at the end, the expression is valid.

 */


#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Error: Stack overflow.\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        return '\0';
    }
    return stack[top--];
}

int is_empty() {
    return top == -1;
}

int is_matching_pair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int is_balanced(const char* expression) {
    top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (is_empty()) {
                return 0;
            }

            char top_char = pop();
            if (!is_matching_pair(top_char, c)) {
                return 0;
            }
        }
    }

    return is_empty();
}

void run_test(const char* expr) {
    if (is_balanced(expr)) {
        printf("Expression '%s' is valid (True)\n", expr);
    } else {
        printf("Expression '%s' is invalid (False)\n", expr);
    }
}

int main() {
    run_test("({[a + b] * (c - d)} / e)");
    run_test("{[})");
    run_test("({");
    run_test("()})");
    run_test("[]{}()");
    run_test("[a * (b + c)]");

    return 0;
}
