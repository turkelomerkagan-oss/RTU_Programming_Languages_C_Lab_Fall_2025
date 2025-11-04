/*
 * week4_1_dynamic_array.c
 * Author: Omer Kagan Turkel
 * Student ID: 231ADB255
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Allocates memory for an integer array, reads values from the user,
 *   computes sum and average, prints results, and frees the memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = NULL;
    int sum = 0;
    float avg = 0.0f;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // Allocate memory for n integers
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read n integers from user input
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Compute average
    avg = (float)sum / n;

    // Print results
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);

    // Free allocated memory
    free(arr);

    return 0;
}
