#include <stdio.h>
// Write a C program to compare the number of comparisons and swaps
// made in Bubble
// Sort, Selection Sort, and Insertion Sort for the same input array.

void bubble_sort(int array[], int array_length) {

    int comparisons = 0;
    int swap = 0;

    for (int i = 0; i < array_length - 1; i++) {
        comparisons++;
        for (int j = 0; j < array_length - i - 1; j++) {
            comparisons++;
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swap++;
            }
        }
    }
    printf("bubble Sort \n");
    printf("comparisons: %d \n",comparisons);
    printf("swap: %d \n",swap);
}

void selection_sort(int array[], int array_length) {
    int comparisons = 0;
    int swap = 0;

    for (int i = 0; i < array_length - 1; i++) {
        int largest_index = 0;

        for (int j = 1; j < array_length - i; j++) {
            comparisons++;
            if (array[j] > array[largest_index]) {
                largest_index = j;
            }
        }
        if (largest_index != array_length - i - 1) {
            swap++;
            int temp = array[largest_index];
            array[largest_index] = array[array_length - i - 1];
            array[array_length - i - 1] = temp;
        }

    }
    printf("Selection Sort \n");
    printf("comparisons: %d \n",comparisons);
    printf("swap: %d \n",swap);

}

void insertion_sort(int array[], int array_length) {

    int comparisons = 0;
    int swap = 0;

    for (int i = 1; i < array_length; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;
            if (array[j] > key) {
                array[j + 1] = array[j];
                swap++;
                j--;
            } else {
                break;
            }
        }
        // Insert the key
        array[j + 1] = key;
    }

    printf("insertion Sort \n");
    printf("comparisons: %d \n",comparisons);
    printf("swap: %d \n",swap);

}

int main() {
    // int array1[] = {41, 5, 6, 2, 32, 35, 43, 53};
    int array1[] = {8,7,6,5,4,3,2,1};
    int array2[] = {8,7,6,5,4,3,2,1};
    int array3[] = {8,7,6,5,4,3,2,1};

    bubble_sort(array1,8);
    selection_sort(array2,8);
    insertion_sort(array3,8);

    return 0;
}