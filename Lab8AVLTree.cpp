#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the AVL tree
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get the height of a node
int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // New node is initially added at the leaf level
    return newNode;
}

// Function to perform a right rotation
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to get the balance factor of a node
int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a key into the AVL tree
struct Node *insert(struct Node *root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys are not allowed

    // Update the height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of the current node
    int balance = getBalance(root);

    // Perform rotations if necessary to balance the tree
    if (balance > 1) {
        if (key < root->left->key) {
            // Left-Left case: Perform a right rotation
            return rightRotate(root);
        } else {
            // Left-Right case: Perform a left rotation on the left child followed by a right rotation on the current node
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balance < -1) {
        if (key > root->right->key) {
            // Right-Right case: Perform a left rotation
            return leftRotate(root);
        } else {
            // Right-Left case: Perform a right rotation on the right child followed by a left rotation on the current node
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to perform an in-order traversal of the AVL tree
void inOrderTraversal(struct Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, key;

    while (1) {
        printf("\nAVL Tree Menu:\n");
        printf("1. Insert\n");
        printf("2. In-Order Traversal\n");
        printf("3. Quit\n");

        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key %d inserted into the AVL tree.\n", key);
                break;
            case 2:
                printf("In-Order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

