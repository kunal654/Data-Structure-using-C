// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

// preorderTraversal traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// postorderTraversal traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

// Create a new Node
struct node* createNode(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

int main() {
  struct node* root = createNode(1);
  insertLeft(root, 12);
  insertRight(root, 9);

  insertLeft(root->left, 5);
  insertRight(root->left, 6);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
int choice;
while(1){
	printf("\n 1.Menu");
	printf("\n 2.Inorder");
	printf("\n 3.Preorder ");
	printf("\n 4.Postorder");
	printf("\n 5.Invalid choice");
	scanf("%d",&choice);
	
	switch(choice){
		case 0:
			case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                if (root == NULL) {
                    root = createNode(value);
                } else {
                    int insertChoice;
                    struct node* current = root;
                    while (1) {
                        printf("Insert as left child (1) or right child (2) of %d: ", current->item);
                        scanf("%d", &insertChoice);
                        if (insertChoice == 1) {
                            if (current->left == NULL) {
                                insertLeft(current, value);
                                break;
                            } else {
                                current = current->left;
                            }
                        } else if (insertChoice == 2) {
                            if (current->right == NULL) {
                                insertRight(current, value);
                                break;
                            } else {
                                current = current->right;
                            }
                        } else {
                            printf("Invalid choice. Try again.\n");
                        }
		case 1:
			printf("Inorder Traversal is ");
			inorderTraversal(root);
			break;
		case 2:
			printf("Preorder Traversal is ");
			preorderTraversal(root);
			break;
		case 3:
			printf("Postorder Traversal is ");
			postorderTraversal(root);
			break;
		case 4:
			printf("Exit");
			exit(0);
			break;
		default:
			printf("Invalid choice");
	}
	
}
}

