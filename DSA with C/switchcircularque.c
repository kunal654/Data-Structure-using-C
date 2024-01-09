#include <stdio.h>
#define size 5

int iteam[size];
int front = -1;
int rear = -1;

int main() {
    int n, c, value,i;
    printf("press 1 to start \n");
    scanf("%d", &n);

    while (n == 1) {
        printf("\n press 1 to insert \n");
        printf("press 2 to delete \n");
        printf("press 3 to display \n");
        printf("press 4 to exit \n");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("enter your element ");
                scanf("%d", &value);

                if ((front == rear + 1) || (front == 0 && rear == size - 1)) {
                    printf("\n sorry the queue is full");
                } else {
                    if (front == -1) {
                        front = 0;
                    }
                    rear = (rear + 1) % size;
                    iteam[rear] = value;
                    printf(" inserted  %d \n", value);
                }
                break;
            case 2:
                if (front == -1) {
                    printf("\n The queue is empty");
                } else {
                    value = iteam[front];
                    if (front == rear) {
                        front = -1;
                        rear = -1;
                    } else {
                        front = (front + 1) % size;
                    }
                    printf("\n deleted element %d \n", value);
                }
                break;
            case 3:
                
                if (front == -1) {
                    printf("\n empty queue \n");
                } else {
                    printf("front %d", front);
                    printf("iteam :");
                    for (i = front; i != rear; i = (i + 1) % size) {
                        printf(" %d ", iteam[i]);
                    }
                    printf(" %d ", iteam[i]);
                    printf("rear=%d", rear);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}

