#include <stdio.h>
#include <stdlib.h>

// Finds the smallest element in an integer array using pointers.
// arr A pointer to the beginning of the array.
//  The number of elements in the array.
// The smallest integer value found in the array.

int findSmallest(int *arr, int size) {
    int smallest = *arr;

    for (int *ptr = arr + 1; ptr < arr + size; ptr++) {
        if (*ptr < smallest) {
            smallest = *ptr;
        }
    }

    return smallest;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array.
    int *array = (int *)malloc(n * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", array + i);
    }


    int smallestElement = findSmallest(array, n);

    printf("\nThe smallest element in the array is: %d\n", smallestElement);

    free(array);
    array = NULL;

    return 0;
}
