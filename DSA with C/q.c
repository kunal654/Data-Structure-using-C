#include <stdio.h>
#define max 5

int main() {
    int qa[max];
    int rare = -1;
    int front = -1;
    int c, i, additem;

    printf("press 1 to start\n");
    scanf("%d", &n);

    while (n == 1) {
        printf("press 1 to insert\n");
        printf("press 2 to delete\n");
        printf("press 3 to display\n");
        printf("press 4 to exit\n");
        scanf("%d", &c);

        switch (c) {
            case 1:
                if (rare == max - 1) {
                    printf("queue overflow\n");
                } else {
                    if (front == -1) {
                        front = 0;
                    }
                    printf("please enter element\n");
                    scanf("%d", &additem);
                    rare = rare + 1;
                    qa[rare] = additem;
                }
                break;
            case 2:
                if (front == -1 || front > rare) {
                    printf("queue underflow\n");
                    return 0;
                } else {
                    printf("element deleted from queue is : %d\n", qa[front]);
                    front = front + 1;
                }
                break;
            case 3:
                if (front == -1) {
                    printf("empty queue\n");
                } else {
                    printf("the queue is :\n");
                    printf("read in the :\n ----> \n");
                    for (i = front; i <= rare; i++) {
                        printf("%d\t", qa[i]);
                        printf("\n");
                    }
                }
                break;
            case 4:
                n = 0;
                break;
            default:
                printf("Invalid choice. Exiting.\n");
                printf("To start again press enter\n");
                break;
        }
    }
    return 0;
}

