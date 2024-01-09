#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    int rows;
    int cols;
    int num_elements;
    Element* elements;
} SparseMatrix;

int main() {
    // Example matrices (you can input your own matrices)
    SparseMatrix mat1 = {
        .rows = 3,
        .cols = 3,
        .num_elements = 3,
        .elements = (Element[]){{0, 1, 2}, {1, 2, 5}, {2, 0, 3}},
    };

    SparseMatrix mat2 = {
        .rows = 3,
        .cols = 3,
        .num_elements = 3,
        .elements = (Element[]){{0, 1, 1}, {1, 2, 4}, {2, 2, 6}},
    };

    // Addition of sparse matrices
    int total_elements = mat1.num_elements + mat2.num_elements;
    Element* sum_elements = (Element*)malloc(total_elements * sizeof(Element));

    int i = 0, j = 0, k = 0;
    while (i < mat1.num_elements && j < mat2.num_elements) {
        if (mat1.elements[i].row < mat2.elements[j].row ||
            (mat1.elements[i].row == mat2.elements[j].row && mat1.elements[i].col < mat2.elements[j].col)) {
            sum_elements[k++] = mat1.elements[i++];
        } else if (mat1.elements[i].row > mat2.elements[j].row ||
                   (mat1.elements[i].row == mat2.elements[j].row && mat1.elements[i].col > mat2.elements[j].col)) {
            sum_elements[k++] = mat2.elements[j++];
        } else {
            sum_elements[k] = mat1.elements[i];
            sum_elements[k++].value += mat2.elements[j++].value;
            i++;
        }
    }
  
    while (ini < mat1.num_elements) {
        sum_elements[k++] = mat1.elements[i++];
    }

    while (j < mat2.num_elements) {
        sum_elements[k++] = mat2.elements[j++];
    }

    SparseMatrix sum;
    sum.rows = mat1.rows;
    sum.cols = mat1.cols;
    sum.num_elements = k;
    sum.elements = sum_elements;

    // Printing the sum of sparse matrices
    printf("Sparse Matrix (Sum):\n");
    for (i = 0; i < sum.num_elements; i++) {
        printf("(%d, %d, %d)\n", sum.elements[i].row, sum.elements[i].col, sum.elements[i].value);
    }

    // Free dynamically allocated memory
    free(sum.elements);

    return 0;
}
