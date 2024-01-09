//Input a multi word string and reverse it with respect to the words. Use a stack to solve the problem.

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

struct Stack {
    char words[MAX_LENGTH][MAX_LENGTH];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, const char *word) {
    if (s->top < MAX_LENGTH - 1) {
        s->top++;
        strcpy(s->words[s->top], word);
    }
}

void pop(struct Stack *s, char *word) {
    if (s->top >= 0) {
        strcpy(word, s->words[s->top]);
        s->top--;
    }
}

void main() {
//    char input[MAX_LENGTH] = "my name is kunal";
    char input[MAX_LENGTH];
    printf("Enter your sentence \n");
    scanf("%[^\n]", input);  // Read the whole line
	char reversed[MAX_LENGTH] = "";

    struct Stack wordStack;
    initialize(&wordStack);

    char *token = strtok(input, " ");
    while (token != NULL) {
        push(&wordStack, token);
        token = strtok(NULL, " ");
    }

    while (wordStack.top >= 0) {
        char w[MAX_LENGTH];
        pop(&wordStack, w);
        strcat(reversed, w);
        strcat(reversed, " ");
    }

    printf("Reversed string: %s\n", reversed);
}
