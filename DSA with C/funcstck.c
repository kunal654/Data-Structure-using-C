#include <stdio.h>
#define MAX_SIZE 7
int i;
void push(int stack[], int *top) {
    if (*top == (MAX_SIZE - 1)) {
        printf("\nStack is full");
    } else {
        int a;
        printf("\nEnter the element: ");
        scanf("%d", &a);
        stack[++(*top)] = a;
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("\nStack is empty");
    } else {
        printf("\nPop element is: %d", stack[(*top)--]);
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("\nStack is empty");
    } else {
        printf("\nStack elements from bottom to top: ");
        for ( i = 0; i <= top; i++) {
            printf("%d", stack[i]);
            if (i != top) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main() {
    int stack[MAX_SIZE];
    int top = -1;
    int choice, flag = 1;

    while (flag != 0) {
        printf("\nPress 1 for push");
        printf("\nPress 2 for pop");
        printf("\nPress 3 for display");
        printf("\nPress 4 for exit");
        printf("\n");
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            // Handle invalid input
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
