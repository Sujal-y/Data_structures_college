// Design and implement a C program to efficiently represent and perform basic
// operations on a sparse matrix using a suitable data structure.
// Case Study: Consider a 5x5 sparse matrix where the non-zero elements are:
// (5, 5, 5), (0, 2, 5), (1, 1, 9), (2, 4, 3), (3, 0, 7), (4, 3, 1)
// Implementation: Implement the following functions in C:
// • createSparseMatrix(int rows, int cols, int numNonZero): Initializes the sparse
// matrix structure.
// • insertElement(SparseMatrix* matrix, int row, int col, int value): Inserts a non-
// zero element into the sparse matrix.
// • displaySparseMatrix(SparseMatrix* matrix): Displays the sparse matrix in a user-
// friendly format (e.g., triplet form or a reconstructed 2D matrix).

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
    int numNonZero;
    int currentCount;
    Element *elements;
} SparseMatrix;

SparseMatrix* createSparseMatrix(int rows, int cols, int numNonZero) {
    SparseMatrix *matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    if (matrix == NULL) {
        printf("Error: Could not allocate memory for matrix structure.\n");
        return NULL;
    }

    matrix->elements = (Element*)malloc(numNonZero * sizeof(Element));
    if (matrix->elements == NULL) {
        printf("Error: Could not allocate memory for elements array.\n");
        free(matrix);
        return NULL;
    }

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->numNonZero = numNonZero;
    matrix->currentCount = 0;

    return matrix;
}

void insertElement(SparseMatrix* matrix, int row, int col, int value) {
    if (matrix == NULL) {
        printf("Error: Matrix is NULL.\n");
        return;
    }

    if (row >= matrix->rows || col >= matrix->cols || row < 0 || col < 0) {
        printf("Error: Element (%d, %d, %d) is out of bounds for a %dx%d matrix.\n",
               row, col, value, matrix->rows, matrix->cols);
        return;
    }

    if (matrix->currentCount >= matrix->numNonZero) {
        printf("Error: Matrix storage is full. Cannot add element (%d, %d, %d).\n",
               row, col, value);
        return;
    }

    matrix->elements[matrix->currentCount].row = row;
    matrix->elements[matrix->currentCount].col = col;
    matrix->elements[matrix->currentCount].value = value;
    matrix->currentCount++;
}

int getValue(SparseMatrix* matrix, int row, int col) {
    for (int i = 0; i < matrix->currentCount; i++) {
        if (matrix->elements[i].row == row && matrix->elements[i].col == col) {
            return matrix->elements[i].value;
        }
    }
    return 0;
}

void displaySparseMatrix(SparseMatrix* matrix) {
    if (matrix == NULL) {
        printf("Error: Matrix is NULL.\n");
        return;
    }

    printf("--- Sparse Matrix in Triplet Form (Row, Col, Value) ---\n");
    printf("Dimensions: %d rows, %d cols, %d non-zero elements\n",
           matrix->rows, matrix->cols, matrix->currentCount);
    for (int i = 0; i < matrix->currentCount; i++) {
        printf("(%d, %d, %d)\n",
               matrix->elements[i].row,
               matrix->elements[i].col,
               matrix->elements[i].value);
    }

    printf("\n--- Reconstructed 2D Matrix ---\n");
    for (int r = 0; r < matrix->rows; r++) {
        for (int c = 0; c < matrix->cols; c++) {
            printf("%d\t", getValue(matrix, r, c));
        }
        printf("\n");
    }
}

void freeSparseMatrix(SparseMatrix* matrix) {
    if (matrix != NULL) {
        free(matrix->elements);
        free(matrix);
Next, update the main function:
    }
}

int main() {
    int rows = 5;
    int cols = 5;
    int numNonZero = 6;

    SparseMatrix *matrix = createSparseMatrix(rows, cols, numNonZero);

    if (matrix == NULL) {
        return 1;
    }

    insertElement(matrix, 0, 2, 5);
    insertElement(matrix, 1, 1, 9);
    insertElement(matrix, 2, 4, 3);
    insertElement(matrix, 3, 0, 7);
    insertElement(matrix, 4, 3, 1);
    insertElement(matrix, 4, 4, 5);

    displaySparseMatrix(matrix);

    freeSparseMatrix(matrix);
    matrix = NULL;

    return 0;
}

