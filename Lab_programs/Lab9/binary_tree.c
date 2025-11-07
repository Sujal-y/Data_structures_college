//binary tree

#include<stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};

struct node* createnode()
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->left_child =NULL;
    newnode->right_child =NULL;
    return newnode;
}

//recursive binary tree
struct node* create_binary_tree(int item)
{
    int x;
    if (item != -1)
    {
        struct node* temp = createnode();
        temp->data=item;
        printf("enter the value of left child of %d(-1 for no child):- ",item);
        scanf("%d",&x);
        temp->left_child = create_binary_tree(x);
        printf("enter the value of right child of %d(-1 for no child):- ",item);
        scanf("%d",&x);
        temp->right_child = create_binary_tree(x);
        return temp;
    }

    return NULL;
}

// recursive preorder
void preorder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left_child);
    preorder(root->right_child);
}
//recursive in order
void in_order(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    in_order(root->left_child);
    printf("%d ",root->data);
    in_order(root->right_child);
}
//recursive post order
void post_order(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    post_order(root->left_child);
    post_order(root->right_child);
    printf("%d ",root->data);
}

//iterative preorder we will use stack
void iterative_preorder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    struct node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1)//while stack is not empty
    {
        struct node* current = stack[top--];
        printf("%d ", current->data);

        // Push right child first so it's processed after left
        if (current->right_child != NULL)
            stack[++top] = current->right_child;

        // Push left child last so it's processed next
        if (current->left_child != NULL)
            stack[++top] = current->left_child;
    }
}
//iterative inorder we will use stack
void iterative_inorder(struct node* root) {
    struct node* stack[100];
    int top = -1;
    struct node* current = root;
    while (current != NULL || top > -1) // pop
    {
        while (current != NULL) // travel leftmost of current subtree
        {stack[++top] = current;
            current = current->left_child; }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right_child;
    }
}
//iterative postorder we will use stack
void iterative_postorder(struct node* root) {
    if (root == NULL)
        return;
    struct node* current = root;
    struct node* prev = NULL;
    struct node* stack[100];
    int top = -1;
    do { while (current != NULL)
        {
        stack[++top] = current;
        current = current->left_child;
        }
        while (current == NULL && top != -1)
            {
            current = stack[top];
            // If the right child is either not present or has been visited
            if (current->right_child == NULL || current->right_child == prev) {
                printf("%d ", current->data); top--;
                prev = current;
                current = NULL; }
            // Else traverse the right child
            else {
                current = current->right_child;
            }
        }
    } while (top != -1);
}

// --- Queue for Level-Order ---
struct QNode {
    struct node* treeNode;
    struct QNode* next;
};

struct Queue {
    struct QNode *front;
    struct QNode *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isQueueEmpty(struct Queue* q) {
    return (q->front == NULL);
}

void enqueue(struct Queue* q, struct Node* treeNode) {
    struct QNode* newNode = (struct QNode*)malloc(sizeof(struct QNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

struct node* dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }
    struct QNode* temp = q->front;
    struct node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return treeNode;
}
// --- End of Queue ---

void printLevelOrder(struct node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        struct node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left_child != NULL) {
            enqueue(q, current->left_child);
        }

        if (current->right_child != NULL) {
            enqueue(q, current->right_child);
        }
    }

    free(q);
}

//searching
// Corrected recursive search function
// Returns 1 (true) if found, 0 (false) if not.
int Search(struct node* root, int ele)
{
    // Base case 1: We reached a NULL leaf, element not found.
    if (root == NULL) {
        return 0;
    }

    // Base case 2: We found the element!
    if (root->data == ele) {
        return 1;
    }

    // Recursive step: Search in the left OR the right subtree
    // If it's found in the left, return 1.
    if (Search(root->left_child, ele) == 1) {
        return 1;
    }

    // If not in left, return the result of the right subtree.
    return Search(root->right_child, ele);
}

/*recursive function to copy a tree*/
struct node* copy(struct node* root) {
    // 1. Base case: If the original node is NULL, the copy is NULL.
    if (root == NULL)
        return NULL;

    // 2. Create a new node using YOUR createnode function
    struct node* temp = createnode();

    // 3. Copy the data
    temp->data = root->data;

    // 4. Recursively copy the left and right subtrees
    temp->left_child = copy(root->left_child);
    temp->right_child = copy(root->right_child);

    // 5. Return the newly created node
    return temp;
}
//comapres 2 binary tree
int Equal( struct node* root1, struct node* root2)
{
    return ((!root1 && !root2) || (root1 && root2 && (root1->data == root2->data)
        && Equal( root1->left_child,root2->left_child)
        && Equal ( root1->right_child,root2->right_child)));

}
//counts leaf nodes
// Correct recursive function to count leaf nodes
int count_leafnodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    // Base case 2: This node is a leaf. Return 1.
    if (root->left_child == NULL && root->right_child == NULL) {
        return 1;
    }
    // Recursive step:
    // This node is not a leaf, so its leaf count is the
    // sum of leaves in its left subtree + leaves in its right subtree.
    return count_leafnodes(root->left_child) + count_leafnodes(root->right_child);
}

//count nodes
int count_nodes(struct node* root)
{
    if (root == NULL) {
        return 0;
    }

    // Recursive step:
    // The total count is 1 (for the current node)
    // plus whatever its left and right subtrees return.
    return 1 + count_nodes(root->left_child) + count_nodes(root->right_child);
}

// --- v) Print the depth (or height) of the tree ---

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * @brief Recursively finds the height (max depth) of the tree.
 * Height is defined as the number of edges on the longest path
 * from the root to a leaf.
 * - An empty tree (NULL) has a height of -1.
 * - A tree with one node (root only) has a height of 0.
 */
int find_height(struct node* root) {
    if (root == NULL) {
        return -1;
    }

    // Find the height of the left and right subtrees
    int left_height = find_height(root->left_child);
    int right_height = find_height(root->right_child);

    // The height of this node is 1 + the max of its children's heights
    return 1 + max(left_height, right_height);
}


// --- iv) Print the parent of a given element ---

/**
 * @brief Helper function to find the parent node.
 * This function searches the tree for the 'key' and returns its parent.
 */
struct node* find_parent_helper(struct node* root, int key) {
    // Base case: empty tree or a leaf node (no children to check)
    if (root == NULL || (root->left_child == NULL && root->right_child == NULL)) {
        return NULL;
    }

    // Check if an immediate child matches the key
    if ((root->left_child != NULL && root->left_child->data == key) ||
        (root->right_child != NULL && root->right_child->data == key))
    {
        return root; // This node is the parent
    }

    // Recursive step: Search in the left subtree
    struct node* parent_found = find_parent_helper(root->left_child, key);

    // If found in the left, return it
    if (parent_found != NULL) {
        return parent_found;
    }

    // Otherwise, search in the right subtree and return its result
    return find_parent_helper(root->right_child, key);
}

/**
 * @brief Main function to print the parent of a node.
 * This is a "wrapper" that handles edge cases like the root or "not found".
 */
void print_parent(struct node* root, int key) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    // Handle edge case: key is the root node
    if (root->data == key) {
        printf("Element %d is the root and has no parent.\n", key);
        return;
    }

    struct node* parent = find_parent_helper(root, key);

    if (parent != NULL) {
        printf("Parent of %d is: %d\n", key, parent->data);
    } else {
        printf("Element %d not found in the tree.\n", key);
    }
}


// --- vi) Print the ancestors of a given element ---

/**
 * @brief Recursively finds the 'key' and prints all ancestors.
 * @return 1 (true) if the key is found in this subtree, 0 (false) otherwise.
 */
int print_ancestors_recursive(struct node* root, int key) {
    // Base case 1: Empty tree, key not found
    if (root == NULL) {
        return 0;
    }

    // Base case 2: Key is found! Signal "true" back up the call stack.
    if (root->data == key) {
        return 1;
    }

    // Recursive step: Search in the left OR right subtrees
    if (print_ancestors_recursive(root->left_child, key) == 1 ||
        print_ancestors_recursive(root->right_child, key) == 1)
    {
        // If either call returned true, it means the key was found
        // in a subtree of this node. Therefore, this node is an ancestor.
        printf("%d ", root->data);

        // Signal "true" back up to *this node's* parent
        return 1;
    }

    // Key was not found in either subtree
    return 0;
}

// Wrapper function to print ancestors and handle "not found".
void print_ancestors(struct node* root, int key) {
    printf("Ancestors of %d: ", key);
    int found = print_ancestors_recursive(root, key);

    if (found == 0) {
        printf("Element not found or is the root.\n");
    } else {
        printf("\n"); // Add a newline for clean formatting
    }
}

int main()
{
    printf("create a binary tree\n");
    printf("enter the root node");
    int x;
    scanf("%d",&x);
    struct node* head =create_binary_tree(x);

    printf("\n preorder: ");
    preorder(head);

    printf("\n inorder: ");
    in_order(head);


    printf("\n postorder: ");
    post_order(head);

    printf("\n iterative methods--- \n");

    printf("\n preorder: ");
    iterative_preorder(head);

    printf("\n inorder: ");
    iterative_inorder(head);


    printf("\n postorder: ");
    iterative_postorder(head);

    printf("\nlevel order------\n");
    printLevelOrder(head);

    printf("\n\n--- Tree 1 Counts ---");
    printf("\nTotal nodes: %d", count_nodes(head));
    printf("\nLeaf nodes: %d", count_leafnodes(head));

    printf("\n\n--- Test Search ---");
    int key;
    printf("\nEnter a value to search for in Tree 1: ");
    scanf("%d", &key);
    if (Search(head, key)) {
        printf("Result: %d was found in Tree 1.\n", key);
    } else {
        printf("Result: %d was NOT found in Tree 1.\n", key);
    }

    printf("\n--- Test Copy Function ---");
    struct node* head_copy = copy(head);
    printf("\nCreated a copy of Tree 1.");
    printf("\nPreorder of Copy: ");
    preorder(head_copy);

    printf("\n\n--- Test Equal Function (Tree 1 vs. Copy) ---");
    if (Equal(head, head_copy)) {
        printf("\nResult: Tree 1 and its Copy are EQUAL (Success!).\n");
    } else {
        printf("\nResult: Tree 1 and its Copy are NOT EQUAL (Error!).\n");
    }

    printf("\n\n--- v) Find Height ---");
    int height = find_height(head);
    printf("\nHeight of the tree is: %d", height);

    printf("\n\n--- iv) Find Parent ---");
    int key_parent;
    printf("\nEnter element to find parent for: ");
    scanf("%d", &key_parent);
    print_parent(head, key_parent);

    printf("\n--- vi) Find Ancestors ---");
    int key_ancestor;
    printf("\nEnter element to find ancestors for: ");
    scanf("%d", &key_ancestor);
    print_ancestors(head, key_ancestor);




}