#include<stdio.h>
// Write a recursive C program to implement Selection Sort using pointers.
// • The recursive function should sort the array using the Selection Sort algorithm.
// • Access and manipulate the array elements using pointers (i.e., avoid using arr[i]nstyle directly).
// • The program should read the array from the user in the main function, call the
// recursive sorting function, and display the sorted array.
void array_entry(int a[],int n) {
    printf("enter the elements:- \n");
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
}

void display_array(int a[],int n) {
    printf("The elements in the array:- \n");
    for (int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSortRecursive(int *arr, int i, int n) {
    // Base case
    if (i >= n - 1) {
        return;
    }

    // Find the index of the minimum element
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
        if (*(arr + j) < *(arr + min_idx)) {
            min_idx = j;
        }
    }

    if (min_idx != i) {
        swap((arr + min_idx), (arr + i));
    }

    //recursion with the next element until the last one
    selectionSortRecursive(arr, i + 1, n);
}

int main() {
    printf("Enter how many elements:- ");
    int n;
    scanf("%d",&n);
    int array[n];
    array_entry(array,n);

    selectionSortRecursive(array,0,n);

    display_array(array,n);


    return 0;
}
