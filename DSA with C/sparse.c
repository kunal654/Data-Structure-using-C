//Input value into  2d array and check weather it is a sparse matrix or not if a matrix is sparse matrix generate the coordinate
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS];
    int numNonZero = 0;
    int i,j;

    // Input values into the matrix
    printf("Enter matrix elements:\n");
    for ( i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                numNonZero++;
            }
        }
    }

    // Check if it's a sparse matrix
    int totalElements = ROWS * COLS;
    float threshold = 0.5; // Set a threshold for sparsity
    if ((float)numNonZero / totalElements < threshold) {
        printf("The matrix is a sparse matrix.\n");

        // Generate and print the coordinates of non-zero elements
        int i,j;
        printf("Coordinates of non-zero elements:\n");
        for ( i = 0; i < ROWS; i++) {
            for ( j = 0; j < COLS; j++) {
                if (matrix[i][j] != 0) {
                    printf("(%d, %d)\n", i, j);
                    
                }
            }
        }
    } else {
        printf("The matrix is not a sparse matrix.\n");
    }

    return 0;
}

