// Given the following sequence of ISBNs to be inserted into an initially empty
// Binary Search Tree: [50, 30, 70, 20, 40, 60, 80, 10, 25, 55, 65, 75, 85],
// perform the following operations and illustrate the state of the BST after each step:
// Insertion: Construct the BST by inserting all ISBNs from the given sequence.
// Search: Demonstrate the search operation for ISBN 60 and 90. Clearly indicate the path taken for each search.
// Deletion: Delete the node with ISBN 70. Describe the steps involved in handling this deletion, especially
// considering if the node has one child, two children, or no children.
// Traversal: Perform an in-order traversal of the final BST and list the ISBNs in the order they are visited.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int isbn;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int isbn) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->isbn = isbn;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int isbn) {
    if (node == NULL) {
        return createNode(isbn);
    }
    if (isbn < node->isbn) {
        node->left = insert(node->left, isbn);
    } else if (isbn > node->isbn) {
        node->right = insert(node->right, isbn);
    }
    return node;
}

Node* search(Node* root, int isbn) {
    if (root == NULL) {
        printf("Path: (NULL)\n");
        return NULL;
    }

    printf("%d", root->isbn);

    if (root->isbn == isbn) {
        printf("\n");
        return root;
    }

    if (isbn < root->isbn) {
        printf(" -> ");
        return search(root->left, isbn);
    } else {
        printf(" -> ");
        return search(root->right, isbn);
    }
}

Node* findMin(Node* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, int isbn) {
    if (root == NULL) {
        return root;
    }

    if (isbn < root->isbn) {
        root->left = deleteNode(root->left, isbn);
    } else if (isbn > root->isbn) {
        root->right = deleteNode(root->right, isbn);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->isbn = temp->isbn;
        root->right = deleteNode(root->right, temp->isbn);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->isbn);
        inorderTraversal(root->right);
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
    Node* root = NULL;
    int isbns[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 55, 65, 75, 85};
    int n = sizeof(isbns) / sizeof(isbns[0]);

    printf("--- Insertion ---\n");
    for (int i = 0; i < n; i++) {
        printf("Inserting %d\n", isbns[i]);
        root = insert(root, isbns[i]);
    }

    printf("\n--- In-order Traversal After Insertion ---\n");
    inorderTraversal(root);
    printf("\n");

    printf("\n--- Search for 60 ---\n");
    printf("Path: ");
    Node* result60 = search(root, 60);
    if (result60 != NULL) {
        printf("Result: Found 60\n");
    } else {
        printf("Result: Not Found\n");
    }

    printf("\n--- Search for 90 ---\n");
    printf("Path: ");
    Node* result90 = search(root, 90);
    if (result90 != NULL) {
        printf("Result: Found 90\n");
    } else {
        printf("Result: Not Found\n");
    }

    printf("\n--- Deletion of 70 ---\n");
    root = deleteNode(root, 70);
    printf("Deleted 70. (Replaced with in-order successor, 75)\n");

    printf("\n--- Final In-order Traversal ---\n");
    inorderTraversal(root);
    printf("\n");

    freeTree(root);

    return 0;
}

