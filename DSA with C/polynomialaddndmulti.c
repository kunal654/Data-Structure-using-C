#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;

    // Insert terms into polynomial 1
    struct Term* term1 = (struct Term*)malloc(sizeof(struct Term));
    term1->coefficient = 3;
    term1->exponent = 4;
    term1->next = NULL;
    poly1 = term1;

    struct Term* term2 = (struct Term*)malloc(sizeof(struct Term));
    term2->coefficient = 2;
    term2->exponent = 3;
    term2->next = NULL;
    term1->next = term2;

    struct Term* term3 = (struct Term*)malloc(sizeof(struct Term));
    term3->coefficient = 5;
    term3->exponent = 1;
    term3->next = NULL;
    term2->next = term3;

    // Insert terms into polynomial 2
    struct Term* term4 = (struct Term*)malloc(sizeof(struct Term));
    term4->coefficient = 1;
    term4->exponent = 3;
    term4->next = NULL;
    poly2 = term4;

    struct Term* term5 = (struct Term*)malloc(sizeof(struct Term));
    term5->coefficient = 2;
    term5->exponent = 2;
    term5->next = NULL;
    term4->next = term5;

    struct Term* term6 = (struct Term*)malloc(sizeof(struct Term));
    term6->coefficient = 3;
    term6->exponent = 0;
    term6->next = NULL;
    term5->next = term6;

    // Display Polynomial 1
    printf("Polynomial 1: ");
    struct Term* current1 = poly1;
    while (current1 != NULL) {
        printf("%dx^%d ", current1->coefficient, current1->exponent);
        current1 = current1->next;
        if (current1 != NULL) {
            printf("+ ");
        }
    }
    printf("\n");

    // Display Polynomial 2
    printf("Polynomial 2: ");
    struct Term* current2 = poly2;
    while (current2 != NULL) {
        printf("%dx^%d ", current2->coefficient, current2->exponent);
        current2 = current2->next;
        if (current2 != NULL) {
            printf("+ ");
        }
    }
    printf("\n");

    // Polynomial Addition
    struct Term* resultAdd = NULL;
    struct Term* currentAdd1 = poly1;
    struct Term* currentAdd2 = poly2;

    while (currentAdd1 != NULL && currentAdd2 != NULL) {
        struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
        if (currentAdd1->exponent > currentAdd2->exponent) {
            newTerm->coefficient = currentAdd1->coefficient;
            newTerm->exponent = currentAdd1->exponent;
            currentAdd1 = currentAdd1->next;
        } else if (currentAdd2->exponent > currentAdd1->exponent) {
            newTerm->coefficient = currentAdd2->coefficient;
            newTerm->exponent = currentAdd2->exponent;
            currentAdd2 = currentAdd2->next;
        } else {
            newTerm->coefficient = currentAdd1->coefficient + currentAdd2->coefficient;
            newTerm->exponent = currentAdd1->exponent;
            currentAdd1 = currentAdd1->next;
            currentAdd2 = currentAdd2->next;
        }
        newTerm->next = NULL;

        if (resultAdd == NULL) {
            resultAdd = newTerm;
        } else {
            struct Term* currentResult = resultAdd;
            while (currentResult->next != NULL) {
                currentResult = currentResult->next;
            }
            currentResult->next = newTerm;
        }
    }

    // Display Polynomial Addition Result
    printf("Polynomial Addition Result: ");
    struct Term* currentAddResult = resultAdd;
    while (currentAddResult != NULL) {
        printf("%dx^%d ", currentAddResult->coefficient, currentAddResult->exponent);
        currentAddResult = currentAddResult->next;
        if (currentAddResult != NULL) {
            printf("+ ");
        }
    }
    printf("\n");

    // Polynomial Multiplication
    struct Term* resultMultiply = NULL;
    struct Term* currentMult1 = poly1;
    while (currentMult1 != NULL) {
        struct Term* currentMult2 = poly2;
        while (currentMult2 != NULL) {
            struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
            newTerm->coefficient = currentMult1->coefficient * currentMult2->coefficient;
            newTerm->exponent = currentMult1->exponent + currentMult2->exponent;
            newTerm->next = NULL;

            if (resultMultiply == NULL) {
                resultMultiply = newTerm;
            } else {
                struct Term* currentResult = resultMultiply;
                while (currentResult->next != NULL) {
                    currentResult = currentResult->next;
                }
                currentResult->next = newTerm;
            }

            currentMult2 = currentMult2->next;
        }
        currentMult1 = currentMult1->next;
    }

    // Display Polynomial Multiplication Result
    printf("Polynomial Multiplication Result: ");
    struct Term* currentMultResult = resultMultiply;
    while (currentMultResult != NULL) {
        printf("%dx^%d ", currentMultResult->coefficient, currentMultResult->exponent);
        currentMultResult = currentMultResult->next;
        if (currentMultResult != NULL) {
            printf("+ ");
        }
    }
    printf("\n");

    // Free allocated memory for polynomial 1
    while (poly1 != NULL) {
        struct Term* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }

    // Free allocated memory for polynomial 2
    while (poly2 != NULL) {
        struct Term* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }

    // Free allocated memory for polynomial addition result
    while (resultAdd != NULL) {
        struct Term* temp = resultAdd;
        resultAdd = resultAdd->next;
        free(temp);
    }

    // Free allocated memory for polynomial multiplication result
    while (resultMultiply != NULL) {
        struct Term* temp = resultMultiply;
        resultMultiply = resultMultiply->next;
        free(temp);
    }

    return 0;
}

