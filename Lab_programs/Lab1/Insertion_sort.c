//insertion sort
#include <stdio.h>

int main() {
    int array[] = {41, 5, 6, 2, 32, 35, 43, 53};
    int array_length = 8;

    for (int i = 1; i < array_length; i++) {
        int key = array[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        // Insert the key
        array[j + 1] = key;
    }

    // Print sorted array
    for (int i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}