#include<stdio.h>
#include<stdlib.h>
#define max 10
int count=0;

struct stack {
    int items[max];
    int top;
};
typedef struct stack st;

void emptystack(st *s) {
    s->top = -1;
}

int isfull(st *s) {
    if (s->top == max - 1)
        return 1;
    else
        return 0;
}

int isempty(st *s) {
    if (s->top == -1) {
        return 1;
    }
    else
        return 0;
}

void push(st *s, int items) {
    if (isfull(s)) {
        printf("stack is full");
    }
    else {
        s->top++;
        s->items[s->top] = items;  // Changed '==' to '='
    }
    count++;
}

int pop(st *s) {
    if (isempty(s)) {
        printf("stack is empty");
        return -1;
    }
    else {
        printf("item pop=%d", s->items[s->top]);
        s->top--;
        count--;  // Moved count decrement here
        printf("\n");
        return 1;
    }
}

void display(st *s) {
    int i;
    printf("stack");
    for (i = 0; i < count; i++) {
        printf("%d", s->items[i]);
    }
    printf("\n");
}

int main() {
    int ch, items;
    struct stack s;
    emptystack(&s);
    while (1) {
        printf("\nstack options are:");
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.display");
        printf("\n4.exit");  // Changed 'exit' to '4.exit'

        printf("\nenter your choice:");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("enter the item to be inserted:");
                scanf("%d", &items);
                push(&s, items);
                break;
            case 2:
                items = pop(&s);
                if (items != -1) {
                    printf("Popped item:%d\n", items);
                }
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("exiting the program");
                exit(0);
            default:
                printf("invalid choice");
        }
    }
}
