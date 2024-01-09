#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Stack implementation using linked list
struct Stack {
    struct Node* top;
};

// Queue implementation using linked list
struct Queue {
    struct Node* front;
    struct Node* rear;
};

int main() {
    struct Stack stack;
    struct Queue queue;
    
    stack.top = NULL;
    queue.front = NULL;
    queue.rear = NULL;

    int choice, data;
    do {
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Enqueue (Queue)\n");
        printf("4. Dequeue (Queue)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push (Stack)
                printf("Enter data: ");
                scanf("%d", &data);
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->next = stack.top;
                stack.top = newNode;
                printf("Element pushed onto stack.\n");
                break;

            case 2: // Pop (Stack)
                if (stack.top == NULL) {
                    printf("Stack is empty.\n");
                } else {
                    struct Node* temp = stack.top;
                    stack.top = stack.top->next;
                    printf("Popped element: %d\n", temp->data);
                    free(temp);
                }
                break;

            case 3: // Enqueue (Queue)
                printf("Enter data: ");
                scanf("%d", &data);
                struct Node* newQueueNode = (struct Node*)malloc(sizeof(struct Node));
                newQueueNode->data = data;
                newQueueNode->next = NULL;
                
                if (queue.rear == NULL) {
                    queue.front = newQueueNode;
                    queue.rear = newQueueNode;
                } else {
                    queue.rear->next = newQueueNode;
                    queue.rear = newQueueNode;
                }
                printf("Element enqueued into queue.\n");
                break;

            case 4: // Dequeue (Queue)
                if (queue.front == NULL) {
                    printf("Queue is empty.\n");
                } else {
                    struct Node* tempQueue = queue.front;
                    queue.front = queue.front->next;
                    printf("Dequeued element: %d\n", tempQueue->data);
                    free(tempQueue);
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    // Free allocated memory for stack
    while (stack.top != NULL) {
        struct Node* temp = stack.top;
        stack.top = stack.top->next;
        free(temp);
    }

    // Free allocated memory for queue
    while (queue.front != NULL) {
        struct Node* tempQueue = queue.front;
        queue.front = queue.front->next;
        free(tempQueue);
    }

    return 0;
}

