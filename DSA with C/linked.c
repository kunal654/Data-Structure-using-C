#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* current = NULL;

    int choice, data;
    do {
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->next = NULL;
                
                if (head == NULL) {
                    head = newNode;
                    current = head;
                } else {
                    current->next = newNode;
                    current = newNode;
                }
                printf("Data inserted successfully.\n");
                break;

            case 2:
                printf("Linked List: ");
                current = head;
                while (current != NULL) {
                    printf("%d -> ", current->data);
                    current = current->next;
                }
                printf("NULL\n");
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    // Free allocated memory
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

