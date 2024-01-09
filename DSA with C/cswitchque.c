#include <stdio.h>
#define size 5

int items[size];
int front = -1;
int rear = -1;

int isFull() {
    return (front == rear + 1) || (front == 0 && rear == size - 1);
}

int isEmpty() {
    return front == -1;
}

int main() {
    int n, c, value,i;
    printf("Press 1 to start\n");
    scanf("%d", &n);
    while (n == 1) {
        printf("\nPress 1 to insert\n");
        printf("Press 2 to delete\n");
        printf("Press 3 to display\n");
        printf("Press 4 to exit\n");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter your element: ");
                scanf("%d", &value);
                if (isFull()) {
                    printf("\nSorry, the queue is full.\n");
                } else {
                    if (front == -1) {
                        front = 0;
                    }
                    rear = (rear + 1) % size;
                    items[rear] = value;
                    printf("Inserted: %d\n", value);
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("\nThe queue is empty.\n");
                } else {
                    value = items[front];
                    if (front == rear) {
                        front = rear = -1;
                    } else {
                        front = (front + 1) % size;
                    }
                    printf("Deleted element: %d\n", value);
                }
                break;
            case 3:
                if (isEmpty()) {
                    printf("\nEmpty queue.\n");
                } else {
                    printf("Front: %d\nItems: ", front);
                    for ( i = front; i != (rear + 1) % size; i = (i + 1) % size) {
                     printf("%d ", items[i]);
                    }
                    printf("%d\n", items[rear]);

//                    for (int i = front; i != rear; i = (i + 1) % size) {
//                        printf("%d ", items[i]);
//                    }
//                    printf("%d\n", items[rear]);
                    printf("Rear: %d\n", rear);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

