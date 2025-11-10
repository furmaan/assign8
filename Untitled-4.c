#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for a binary tree node
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
   Recursive function to check if a tree is a BST
   ---------------------------------------------------------- */
int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL)
        return 1;

    // Node must be within min < data < max
    if (root->data <= min || root->data >= max)
        return 0;

    // Recursively check left and right subtrees
    return (isBSTUtil(root->left, min, root->data) &&
            isBSTUtil(root->right, root->data, max));
}

/* ----------------------------------------------------------
   Wrapper function for checking BST
   ---------------------------------------------------------- */
int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

/* ----------------------------------------------------------
   Inorder traversal (for reference)
   ---------------------------------------------------------- */
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* ----------------------------------------------------------
   MAIN FUNCTION
   ---------------------------------------------------------- */
int main() {
    /* Example 1: A valid BST
               4
              / \
             2   6
            / \ / \
           1  3 5  7
    */
    struct Node* root1 = createNode(4);
    root1->left = createNode(2);
    root1->right = createNode(6);
    root1->left->left = createNode(1);
    root1->left->right = createNode(3);
    root1->right->left = createNode(5);
    root1->right->right = createNode(7);

    printf("Inorder Traversal of Tree 1: ");
    inorder(root1);
    printf("\n");

    if (isBST(root1))
        printf("Tree 1 is a Binary Search Tree.\n");
    else
        printf("Tree 1 is NOT a Binary Search Tree.\n");

    /* Example 2: Not a BST
               5
              / \
             2   7
              \
               6   <- violates BST property
    */
    struct Node* root2 = createNode(5);
    root2->left = createNode(2);
    root2->right = createNode(7);
    root2->left->right = createNode(6);

    printf("\nInorder Traversal of Tree 2: ");
    inorder(root2);
    printf("\n");

    if (isBST(root2))
        printf("Tree 2 is a Binary Search Tree.\n");
    else
        printf("Tree 2 is NOT a Binary Search Tree.\n");

    return 0;
}
