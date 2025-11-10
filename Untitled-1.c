#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);   // Visit root
    preorder(root->left);        // Traverse left subtree
    preorder(root->right);       // Traverse right subtree
}
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);         // Traverse left subtree
    printf("%d ", root->data);   // Visit root
    inorder(root->right);        // Traverse right subtree
}
void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);       // Traverse left subtree
    postorder(root->right);      // Traverse right subtree
    printf("%d ", root->data);   // Visit root
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
