//insertion sort
#include <stdio.h>

int main() {
    int array[] = {41, 5, 2, 6, 32, 35, 43, 53};
    int array_length = 8;

    for (int i = 1; i < array_length; i++) {
        int temp = array[i];
        int j = i-1;

        while(j>=0 && array[j]>temp){
            array[j+1] = array[j];
            j--;

        }
        array[j+1] = temp;

    }
    // Print sorted array
    for (int i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}