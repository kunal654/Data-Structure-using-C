//input two coordinate list matrix each representing a sparse matrix perform addition on these two coordinate list to generate the sum of two sparse matrix.
#include <stdio.h>

#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

int main() {
    Element matrixA[MAX_TERMS];
    Element matrixB[MAX_TERMS];
    Element sum[MAX_TERMS];
    
    int rowsA, colsA, nonZeroA;
    int rowsB, colsB, nonZeroB;
    int i;

    printf("\n Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("\n Enter the number of non-zero elements for Matrix A: ");
    scanf("%d", &nonZeroA);

    printf("\n Enter the elements (row column value) for Matrix A:\n");
    for ( i = 0; i < nonZeroA; i++) {
        scanf("%d %d %d", &matrixA[i].row, &matrixA[i].col, &matrixA[i].value);
    }

    printf("\n Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    
    printf("\n Enter the number of non-zero elements for Matrix B: ");
    scanf("%d", &nonZeroB);
    

    printf("\n Enter the elements (row column value) for Matrix B:\n");

    for ( i = 0; i < nonZeroB; i++) {
        scanf("%d %d %d", &matrixB[i].row, &matrixB[i].col, &matrixB[i].value);
    }

    // Perform matrix addition
    int indexA = 0;
    int indexB = 0;
    int indexSum = 0;

    while (indexA < nonZeroA && indexB < nonZeroB) {
        if (matrixA[indexA].row < matrixB[indexB].row ||
            (matrixA[indexA].row == matrixB[indexB].row &&
             matrixA[indexA].col < matrixB[indexB].col)) {
            sum[indexSum] = matrixA[indexA];
            indexA++;
        } else if (matrixB[indexB].row < matrixA[indexA].row ||
                   (matrixB[indexB].row == matrixA[indexA].row &&
                    matrixB[indexB].col < matrixA[indexA].col)) {
            sum[indexSum] = matrixB[indexB];
            indexB++;
        } else {
            sum[indexSum] = matrixA[indexA];
            sum[indexSum].value += matrixB[indexB].value;
            indexA++;
            indexB++;
        }
        indexSum++;
    }

    while (indexA < nonZeroA) {
        sum[indexSum] = matrixA[indexA];
        indexA++;
        indexSum++;
    }

    while (indexB < nonZeroB) {
        sum[indexSum] = matrixB[indexB];
        indexB++;
        indexSum++;
    }

    // Display the sum of the matrices
    printf("Sum of the two sparse matrices:\n");
    for (
	 i = 0; i < indexSum; i++) {
        printf("%d %d %d\n", sum[i].row, sum[i].col, sum[i].value);
    }
    
    return 0;
}

