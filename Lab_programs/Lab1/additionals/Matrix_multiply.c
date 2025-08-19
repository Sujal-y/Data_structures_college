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

int main(){
    //Input of the matrix sizes
    int row1,col1,row2,col2;
    printf("Enter the N x M of matrix A \n");
    scanf("%d %d",&row1,&col1);
    printf("Enter the N x M of matrix B\n");
    scanf("%d %d",&row2,&col2);
    int matrixA[row1][col1];
    int matrixB[row2][col2];

    //input of the matrices
    printf("enter the elements of matrix A \n");
    matrix_2D_entry(row1,col1,matrixA);
    printf("enter the elements of matrix B \n");
    matrix_2D_entry(row2,col2,matrixB);

    if(col1 != row2){
        printf("The matrices are incompatible to multiply");
    }
    else{
        int result[row1][col2];

        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col2; j++) {
                result[i][j] = 0; // Initialize the result element to 0
                for (int k = 0; k < col1; k++) {
                    result[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
        printf("\n The resultant matrix is\n");
        display(row1,col2,result);


    }
    return 0;
}