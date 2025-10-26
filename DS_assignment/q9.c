//Consider a binary tree data structure. Demonstrate and analyze the implementation of Inorder, Preorder, and Postorder traversals using both recursive and iterative approaches.
// Instructions:
// Construct a Binary Tree: Create a sample binary tree with at least 7-9 nodes, ensuring it has both left and right children for some nodes and some leaf nodes. Represent the tree structure clearly (e.g., using a diagram or a textual representation).
// Recursive Traversal Implementation:
// a.
// Provide the pseudocode or code snippets for recursive Inorder, Preorder, and Postorder traversals.
// b.
// Execute these recursive traversals on your sample binary tree and present the output for each.
// Iterative Traversal Implementation:
// c.
// Provide the pseudocode or code snippets for iterative Inorder, Preorder, and Postorder traversals (e.g., using stacks).
// d.
// Execute these iterative traversals on your sample binary tree and present the output for each.
// Comparative Analysis and Observations:
// e.
// Compare the recursive and iterative implementations in terms of code complexity, readability, and efficiency (discussing potential stack overflow issues with recursion for very deep trees).
// f.
// Discuss the specific use cases or scenarios where each traversal method (Inorder, Preorder, Postorder) is most appropriate, providing examples.
// g.
// Analyze any challenges encountered during the implementation of either approach and how they were addressed.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct StackNode {
    Node *tNode;
    struct StackNode *next;
} StackNode;

void push(StackNode **top, Node *tNode) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->tNode = tNode;
    newStackNode->next = *top;
    *top = newStackNode;
}

Node* pop(StackNode **top) {
    if (*top == NULL) return NULL;
    StackNode *temp = *top;
    *top = (*top)->next;
    Node *popped = temp->tNode;
    free(temp);
    return popped;
}

int isStackEmpty(StackNode *top) {
    return top == NULL;
}

void recursivePreorder(Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        recursivePreorder(root->left);
        recursivePreorder(root->right);
    }
}

void recursiveInorder(Node* root) {
    if (root != NULL) {
        recursiveInorder(root->left);
        printf("%c ", root->data);
        recursiveInorder(root->right);
    }
}

void recursivePostorder(Node* root) {
    if (root != NULL) {
        recursivePostorder(root->left);
        recursivePostorder(root->right);
        printf("%c ", root->data);
    }
}

void iterativePreorder(Node* root) {
    if (root == NULL) return;
    StackNode* stack = NULL;
    push(&stack, root);

    while (!isStackEmpty(stack)) {
        Node* node = pop(&stack);
        printf("%c ", node->data);

        if (node->right) push(&stack, node->right);
        if (node->left) push(&stack, node->left);
    }
}

void iterativeInorder(Node* root) {
    StackNode* stack = NULL;
    Node* curr = root;

    while (curr != NULL || !isStackEmpty(stack)) {
        while (curr != NULL) {
            push(&stack, curr);
            curr = curr->left;
        }
        curr = pop(&stack);
        printf("%c ", curr->data);
        curr = curr->right;
    }
}

void iterativePostorder(Node* root) {
    if (root == NULL) return;
    StackNode* s1 = NULL;
    StackNode* s2 = NULL;

    push(&s1, root);
    Node* node;

    while (!isStackEmpty(s1)) {
        node = pop(&s1);
        push(&s2, node);

        if (node->left) push(&s1, node->left);
        if (node->right) push(&s1, node->right);
    }

    while (!isStackEmpty(s2)) {
        node = pop(&s2);
        printf("%c ", node->data);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');
    root->right->right = createNode('G');

    printf("Sample Tree Structure (A is root):\n");
    printf("    A\n");
    printf("   / \\\n");
    printf("  B   C\n");
    printf(" / \\ / \\\n");
    printf("D  E F  G\n\n");

    printf("--- Recursive Traversals ---\n");
    printf("Preorder: ");
    recursivePreorder(root);
    printf("\nInorder:  ");
    recursiveInorder(root);
    printf("\nPostorder: ");
    recursivePostorder(root);
    printf("\n");

    printf("\n--- Iterative Traversals ---\n");
    printf("Preorder: ");
    iterativePreorder(root);
    printf("\nInorder:  ");
    iterativeInorder(root);
    printf("\nPostorder: ");
    iterativePostorder(root);
    printf("\n");

    freeTree(root);

    return 0;
}

