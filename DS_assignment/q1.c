// You are given a sorted array of distinct integers, arr, and a target integer, target. Your
// task is to implement a recursive binary search algorithm to find the index of target
// within arr. If target is not present, the function should return -1.
// Implement the same on the given array to find the element 23.
// arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
// Note: Use dynamic memory allocation functions and pointers to create memory
// and access the elements of an array.

#include <stdio.h>
#include <stdlib.h>

// Recursive binary search function
int recursiveBinarySearch(int *arr, int low, int high, int target) {
    if (low > high) {
        return -1; // Base case: target not found
    }

    int mid = low + (high - low) / 2;
    int midVal = *(arr + mid); // Access element using pointer arithmetic

    if (midVal == target) {
        return mid; // Target found
    } else if (midVal > target) {
        // Search in the left half
        return recursiveBinarySearch(arr, low, mid - 1, target);
    } else {
        // Search in the right half
        return recursiveBinarySearch(arr, mid + 1, high, target);
    }
}

int main() {
    int initial_arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(initial_arr) / sizeof(initial_arr[0]);
    int target = 23;

    // Dynamically allocating memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit with an error
    }

    // Copy elements to the dynamically allocated array using pointers
    for (int i = 0; i < n; i++) {
        *(arr + i) = initial_arr[i];
    }

    // Performing the recursive binary search
    int result = recursiveBinarySearch(arr, 0, n - 1, target);

    // Print the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    // Freeing the dynamically allocated memory
    free(arr);
    arr = NULL;

    return 0;
}
