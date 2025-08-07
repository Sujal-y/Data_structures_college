#include<stdio.h>
void matrix_2D_entry(int row,int col,int matrix[row][col]) {
    printf("Enter elements of matrix:\n");
    for (int i =0 ; i < row; i++) {
        for (int j =0 ; j < col; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
}

void display(int row,int col,int matrix[row][col]) {
    for (int i =0 ; i < row; i++) {
        for (int j =0 ; j < col; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int row,col;
    printf("Enter matrix 1 and 2 size: ");
    scanf("%d %d",&row,&col);
    int matrix1[row][col];
    int matrix2[row][col];
    int matrix3[row][col];

    matrix_2D_entry(row,col,matrix1);
    matrix_2D_entry(row,col,matrix2);

    for (int i =0 ; i < row; i++) {
        for (int j =0 ; j < col; j++) {
            matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }

    printf("Added Matrix:\n");
    display(row,col,matrix3);

return 0;
}