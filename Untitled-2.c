#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* ----------------------------------------------------------
   (a) INSERT FUNCTION – used to build a BST for testing
   ---------------------------------------------------------- */
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    // duplicates are ignored
    return root;
}

/* ----------------------------------------------------------
   (a) SEARCH (Recursive)
   ---------------------------------------------------------- */
struct Node* searchRecursive(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

/* ----------------------------------------------------------
   (a) SEARCH (Non-Recursive / Iterative)
   ---------------------------------------------------------- */
struct Node* searchIterative(struct Node* root, int key) {
    struct Node* current = root;
    while (current != NULL) {
        if (key == current->data)
            return current;
        else if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return NULL; // not found
}

/* ----------------------------------------------------------
   (b) Find Maximum element
   ---------------------------------------------------------- */
struct Node* findMax(struct Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

/* ----------------------------------------------------------
   (c) Find Minimum element
   ---------------------------------------------------------- */
struct Node* findMin(struct Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

/* ----------------------------------------------------------
   (d) In-order Successor (given key)
   ----------------------------------------------------------
   Idea:
   - If node has right subtree → successor is min of right subtree
   - Else → go up to the ancestor for which node is in its left subtree
   ---------------------------------------------------------- */
struct Node* inorderSuccessor(struct Node* root, int key) {
    struct Node* successor = NULL;
    struct Node* current = root;

    while (current != NULL) {
        if (key < current->data) {
            successor = current;
            current = current->left;
        } else if (key > current->data) {
            current = current->right;
        } else {
            // Found node
            if (current->right != NULL)
                successor = findMin(current->right);
            break;
        }
    }
    return successor;
}

/* ----------------------------------------------------------
   (e) In-order Predecessor (given key)
   ----------------------------------------------------------
   Idea:
   - If node has left subtree → predecessor is max of left subtree
   - Else → go up to the ancestor for which node is in its right subtree
   ---------------------------------------------------------- */
struct Node* inorderPredecessor(struct Node* root, int key) {
    struct Node* predecessor = NULL;
    struct Node* current = root;

    while (current != NULL) {
        if (key > current->data) {
            predecessor = current;
            current = current->right;
        } else if (key < current->data) {
            current = current->left;
        } else {
            // Found node
            if (current->left != NULL)
                predecessor = findMax(current->left);
            break;
        }
    }
    return predecessor;
}

/* ----------------------------------------------------------
   Inorder traversal for checking
   ---------------------------------------------------------- */
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* ----------------------------------------------------------
   MAIN FUNCTION
   ---------------------------------------------------------- */
int main() {
    struct Node* root = NULL;

    // Build a sample BST
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = insert(root, elements[i]);

    printf("Inorder Traversal of BST: ");
    inorder(root);
    printf("\n");

    // (a) Search operations
    int key = 40;
    struct Node* res1 = searchRecursive(root, key);
    printf("Recursive Search for %d: %s\n", key, (res1 ? "Found" : "Not Found"));

    struct Node* res2 = searchIterative(root, key);
    printf("Iterative Search for %d: %s\n", key, (res2 ? "Found" : "Not Found"));

    // (b) Maximum element
    printf("Maximum element: %d\n", findMax(root)->data);

    // (c) Minimum element
    printf("Minimum element: %d\n", findMin(root)->data);

    // (d) In-order Successor
    int sKey = 50;
    struct Node* succ = inorderSuccessor(root, sKey);
    if (succ) printf("In-order Successor of %d: %d\n", sKey, succ->data);
    else printf("
