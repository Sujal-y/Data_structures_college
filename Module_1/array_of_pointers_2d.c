#include<stdio.h>
#include <stdlib.h>

void matrix_2D_pointers_entry(int row, int col, int **p) {
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", *(p+i)+j);
        }
    }
}

void display_matrix_pointer(int row, int col, int **p) {
    printf("\nMatrix elements:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", *(*(p+i)+j));
        }
        printf("\n");
    }
}

int main() {
//    int **p,i,j,row=2,col=2;
//    p = (int **)malloc((sizeof(int*)*row));
//    for (int i = 0; i < row;i++) {
//        *(p+i) = (int *) malloc(sizeof(int)*col);
//    }
//    matrix_2D_pointers_entry(row,col,p);
//    display_matrix_pointer(row,col,p);

    int row = 2, col = 2;
    int **ptr = (int **) malloc(sizeof(int) * row);
    for (int i = 0; i < row; i++){
        *(ptr + i) = malloc(sizeof(int)*col);
}
    printf("enter 2d array 2x2\n");
    for(int i=0;i<row;i++){
        for (int j = 0; j < col; j++) {
            scanf("%d",*(ptr+i)+j);
        }
    }

    printf("\n matrix:- \n");
    for(int i=0;i<row;i++){
        for (int j = 0; j < col; j++) {
            printf("%d ",*(*(ptr+i)+j));
        }
        printf("\n");
    }

    return 0;
}
