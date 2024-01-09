#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node *findMin(struct Node *node) {
    struct Node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node *deleteNode(struct Node *root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int search(struct Node *root, int data) {
    if (root == NULL)
        return 0;

    if (root->data == data)
        return 1;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search for a node\n");
        printf("4. Display the tree\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("%d inserted into the tree.\n");
                break;

            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("%d deleted from the tree.\n");
                break;

            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                if (search(root, data))
                    printf("%d found in the tree.\n");
                else
                    printf("%d not found in the tree.\n");
                break;

            case 4:
                printf("Binary Search Tree: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Quitting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
