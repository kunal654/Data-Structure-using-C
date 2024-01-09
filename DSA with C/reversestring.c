#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

struct Stack {
    char words[MAX_LENGTH][MAX_LENGTH];
    int top;
};

int main() {
    char input[MAX_LENGTH];
    printf("Enter your sentence:\n");
    scanf("%[^\n]", input);

    char reversed[MAX_LENGTH] = "";

    struct Stack wordStack;
    wordStack.top = -1;

    char *token = strtok(input, " ");
    while (token != NULL) {
        if (wordStack.top < MAX_LENGTH - 1) {
            wordStack.top++;
            strcpy(wordStack.words[wordStack.top], token);
        }
        token = strtok(NULL, " ");
    }

    while (wordStack.top >= 0) {
        char w[MAX_LENGTH];
        strcpy(w, wordStack.words[wordStack.top]);
        wordStack.top--;
        strcat(reversed, w);
        strcat(reversed, " ");
    }

    printf("Reversed string: %s\n", reversed);

    return 0;
}
