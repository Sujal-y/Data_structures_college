#include<stdio.h>
//Read a square matrix and check whether it is a magic square or not
//(Hint: A magic square is a square matrix in which the sum of every row, column, and both diagonals is the same.)
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
int check_row(int n,int matrix[n][n]){
    int istrue=1;
    int sum_row[n];
    //initialising all sum of rows to 0
    for (int i = 0; i < n; ++i) {
        sum_row[i] = 0;
    }
    //calculating the sum of rows
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum_row[i] += matrix[i][j];
        }
    }
    //verifying weather its true
    for (int i = 0; i < n-1; ++i) {
        if(sum_row[i]!=sum_row[i+1]){
            istrue=0;
        }
    }

    return istrue;
}
int check_col(int n,int matrix[n][n]){
    int istrue=1;
    int sum_col[n];
    //initialising all sum of cols to 0
    for (int i = 0; i < n; ++i) {
        sum_col[i] = 0;
    }
    //calculating the sum of sols
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum_col[i] += matrix[j][i];
        }
    }
    //verifying weather its true
    for (int i = 0; i < n-1; ++i) {
        if(sum_col[i] != sum_col[i + 1]){
            istrue=0;
        }
    }

    return istrue;
}
int check_dia(int n,int matrix[n][n]){
    int istrue=1;
    int left_to_right =0;
    int right_to_left =0;
    
    for (int i = 0; i < n; ++i) {
        left_to_right +=matrix[i][i];
    }

    for (int i = 0; i < n; i++) {
        right_to_left+= matrix[i][(n - 1) - i];
    }
    
    if(left_to_right != right_to_left){
        istrue =0;
    }

    return istrue;
}

int main(){
    printf("enter the size of the array nXn:  ");
    int n;
    scanf("%d",&n);
    int arr[n][n];
    matrix_2D_entry(n,n,arr);

    printf("the matrix :- \n");
    display(n,n,arr);

    if(check_row(n,arr)& check_col(n,arr), check_dia(n,arr)){
        printf("The given array is Magic square!");
    }
    else{
        printf("The given array is not Magic square :<");
    }



    return 0;
}