// Write a function to find the minimum and maximum elements in a BST.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Error: The tree is empty.\n");
        return -1;
    }

    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }

    return current->data;
}

int findMax(struct Node* root) {
    if (root == NULL) {
        printf("Error: The tree is empty.\n");
        return -1;
    }

    struct Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }

    return current->data;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;

    printf("--- Test on empty tree ---\n");
    findMin(root);
    findMax(root);

    printf("\n--- Building tree ---\n");

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Tree built successfully.\n");

    int minVal = findMin(root);
    int maxVal = findMax(root);

    printf("\n--- Results ---\n");
    printf("Minimum element in the BST is: %d\n", minVal);
    printf("Maximum element in the BST is: %d\n", maxVal);

    freeTree(root);
    printf("\nTree memory freed.\n");

    return 0;
}
