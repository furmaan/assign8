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
   (a) INSERT an element (no duplicates allowed)
   ---------------------------------------------------------- */
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate element %d not inserted!\n", data);

    return root;
}

/* ----------------------------------------------------------
   Find minimum node (used in delete)
   ---------------------------------------------------------- */
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

/* ----------------------------------------------------------
   (b) DELETE an existing element
   ---------------------------------------------------------- */
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node to delete found
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Node has two children → replace with inorder successor
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

/* ----------------------------------------------------------
   (c) Maximum Depth (Height) of BST
   ---------------------------------------------------------- */
int maxDepth(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

/* ----------------------------------------------------------
   (d) Minimum Depth of BST
   ---------------------------------------------------------- */
int minDepth(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    if (root->left == NULL)
        return minDepth(root->right) + 1;
    if (root->right == NULL)
        return minDepth(root->left) + 1;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}

/* ----------------------------------------------------------
   Inorder traversal (for checking tree)
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
    int choice, value;

    while (1) {
        printf("\n---- Binary Search Tree Menu ----\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Inorder Traversal\n");
        printf("4. Maximum Depth of BST\n");
        printf("5. Minimum Depth of BST\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Maximum Depth (Height) = %d\n", maxDepth(root));
            break;
        case 5:
            printf("Minimum Depth = %d\n", minDepth(root));
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
