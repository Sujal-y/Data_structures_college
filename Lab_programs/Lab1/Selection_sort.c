//selection sort
#include <stdio.h>

int main() {
    int array[] = {41, 5, 6, 2, 32, 35, 43, 53};
    int array_length = 8;

    for (int i = 0; i < array_length - 1; i++) {
        int largest_index = 0;

        for (int j = 1; j < array_length - i; j++) {
            if (array[j] > array[largest_index]) {
                largest_index = j;
            }
        }


        int temp = array[largest_index];
        array[largest_index] = array[array_length - i - 1];
        array[array_length - i - 1] = temp;
    }

    for (int i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}