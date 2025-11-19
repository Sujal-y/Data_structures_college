/*
 * Complete C program for Binary Search Tree (BST) operations:
 * 1. Create (Insert)
 * 2. Traversals (Inorder, Preorder, Postorder)
 * 3. Search
 * 4. Delete
 * 5. Find Min/Max
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// --- Utility function to create a new node ---
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// --- 1. Function to create/insert a node into the BST ---
struct node* insert(struct node* root, int data) {
    // Base case: If the tree (or subtree) is empty, create the new node here.
    if (root == NULL) {
        return createnode(data);
    }

    // Recursive step: Find the correct spot to insert.
    if (data < root->data) {
        // Go left
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // Go right
        root->right = insert(root->right, data);
    }
    // If data == root->data, do nothing (no duplicates allowed).

    // Return the (possibly modified) root pointer
    return root;
}


// --- 1. Functions for Traversals ---

// Inorder (Left, Root, Right) - Prints in sorted order
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder (Root, Left, Right)
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder (Left, Right, Root)
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


// --- 2. Function to search for an element in the BST ---
struct node* search(struct node* root, int key) {
    // Base case 1: Root is NULL (not found)
    if (root == NULL) {
        return NULL;
    }

    // Base case 2: Key is at the root (found)
    if (root->data == key) {
        return root;
    }

    // Recursive step: Search in the correct subtree
    if (key < root->data) {
        return search(root->left, key);
    } else { // key > root->data
        return search(root->right, key);
    }
}


// --- 4. Functions to find minimum and maximum elements ---

// The minimum is the leftmost node.
struct node* findMin(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    // Keep going left until we can't anymore
    struct node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// The maximum is the rightmost node.
struct node* findMax(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    // Keep going right until we can't anymore
    struct node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}


// --- 3. Function to delete a node from the BST ---
struct node* deleteNode(struct node* root, int key) {
    // --- 1. Find the node ---

    // Base case: Key not in tree
    if (root == NULL) {
        return root;
    }

    // Recursive search for the node
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }

    // --- 2. Node found! (key == root->data) ---
    else {
        // Case 1: Node has 0 or 1 child
        if (root->left == NULL) {// No left child, so replace with right child (or NULL if no children)
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {// No right child, so replace with left child
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node has TWO children
        // We must find the "in-order successor"
        // This is the smallest node in the *right* subtree.
        struct node* temp = findMin(root->right);

        // Copy the successor's data into this node
        root->data = temp->data;

        // Now, delete the successor node from the right subtree
        // This recursive call will always be a Case 1 deletion.
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


// --- Main function to drive the program ---
int main() {
    struct node* root = NULL;
    int choice, data;
    struct node* result;

    // Insert some default data to start with
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Welcome to the BST Operations Program!\n");
    printf("Initial tree (Inorder): ");
    inorder(root);
    printf("\n");

    while (1) {
        printf("\n--- BST Menu ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search for an element\n");
        printf("4. Find Minimum element\n");
        printf("5. Find Maximum element\n");
        printf("6. Print Traversals (Inorder, Preorder, Postorder)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while(getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Element %d inserted.", data);
                printf("\nNew Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Element %d deleted (if it existed).", data);
                printf("\nNew Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter element to search for: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result != NULL) {
                    printf("Element %d was found in the tree.\n", data);
                } else {
                    printf("Element %d was NOT found.\n", data);
                }
                break;

            case 4:
                result = findMin(root);
                if (result != NULL) {
                    printf("The minimum element is: %d\n", result->data);
                } else {
                    printf("The tree is empty.\n");
                }
                break;

            case 5:
                result = findMax(root);
                if (result != NULL) {
                    printf("The maximum element is: %d\n", result->data);
                } else {
                    printf("The tree is empty.\n");
                }
                break;

            case 6:
                printf("Traversals:\n");
                printf("  Inorder:   ");
                inorder(root);
                printf("\n");

                printf("  Preorder:  ");
                preorder(root);
                printf("\n");

                printf("  Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}