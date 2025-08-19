#include <stdio.h>
#include <stdlib.h>

void matrix_2D_entry(int row, int col, int **matrix) {
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", (*(matrix + i) + j));
        }
    }
}

void display(int row, int col, int **matrix) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int row1, col1, row2, col2;
    printf("Enter the N x M of matrix A: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the N x M of matrix B: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2) {
        printf("The matrices are incompatible to multiply.\n");
        return 1;
    }

    // Allocate memory for Matrix A
    int **matrixA = (int **)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++) {
        matrixA[i] = (int *)malloc(col1 * sizeof(int));
    }

    // Allocate memory for Matrix B
    int **matrixB = (int **)malloc(row2 * sizeof(int *));
    for (int i = 0; i < row2; i++) {
        matrixB[i] = (int *)malloc(col2 * sizeof(int));
    }

    // Input matrices
    printf("Enter the elements of matrix A:\n");
    matrix_2D_entry(row1, col1, matrixA);
    printf("Enter the elements of matrix B:\n");
    matrix_2D_entry(row2, col2, matrixB);

    // Allocate memory for the result matrix
    int **result = (int **)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++) {
        result[i] = (int *)malloc(col2 * sizeof(int));
    }

    // Matrix multiplication using pointer dereferencing
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            *(*(result + i) + j) = 0;
            for (int k = 0; k < col1; k++) {
                *(*(result + i) + j) += *(*(matrixA + i) + k) * (*(*(matrixB + k) + j));
            }
        }
    }

    printf("\nThe resultant matrix is:\n");
    display(row1, col2, result);

    // Free the allocated memory
    for (int i = 0; i < row1; i++) {
        free(matrixA[i]);
    }
    free(matrixA);

    for (int i = 0; i < row2; i++) {
        free(matrixB[i]);
    }
    free(matrixB);

    for (int i = 0; i < row1; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}