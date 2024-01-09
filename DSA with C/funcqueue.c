#include <stdio.h>

#define MAX 5

int qa[MAX];
int rear = -1;
int front = -1;

void insert() {
    int additem;

    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    } else {
        if (front == -1) {
            front = 0;
        }
        printf("Please enter an element: \n");
        scanf("%d", &additem);
        rear = rear + 1;
        qa[rear] = additem;
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return;
    } else {
        printf("Element deleted from queue is: %d\n", qa[front]);
        front = front + 1;
        
        // Check if the queue is now empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Empty queue\n");
    } else {
        printf("The queue is:\n");
        printf("Read in the:\n ----> \n");
        for (i = front; i <= rear; i++) {
            printf("%d\t", qa[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, c;

    printf("Press 1 to start\n");
    scanf("%d", &n);

    while (n == 1) {
        printf("Press 1 to insert\n");
        printf("Press 2 to delete\n");
        printf("Press 3 to display\n");
        printf("Press 4 to exit\n");
        scanf("%d", &c);

        switch (c) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                n = 0;
                break;
            default:
                printf("Invalid option\n");
                printf("To start again, press enter\n");
        }
    }

    return 0;
}
