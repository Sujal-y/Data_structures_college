//Bubble Sort
#include <stdio.h>

int main() {
    int array[] = {41, 5, 6, 2, 32, 35, 43, 53};
    int array_length = 8;

    for (int i = 0; i < array_length - 1; i++) {
        for (int j = 0; j < array_length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}