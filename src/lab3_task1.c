/*
 * This program implements several array algorithms:
 *   - Find minimum value
 *   - Find maximum value
 *   - Calculate sum
 *   - Calculate average
 */

#include <stdio.h>

/* ---- Function Prototypes ---- */
int   array_min(int arr[], int size);
int   array_max(int arr[], int size);
int   array_sum(int arr[], int size);
float array_avg(int arr[], int size);

/* ---- Function Implementations ---- */
int array_min(int arr[], int size) {
    if (size <= 0) return 0; // basic safety check
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int array_max(int arr[], int size) {
    if (size <= 0) return 0;
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int array_sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

float array_avg(int arr[], int size) {
    if (size <= 0) return 0.0f;
    return (float)array_sum(arr, size) / (float)size;
}

/* ---- Main Function (Testing) ---- */
int main(void) {
    int arr[] = {10, 20, 5, 30, 15};
    int size = 5;

    printf("Min: %d\n", array_min(arr, size));   // 5
    printf("Max: %d\n", array_max(arr, size));   // 30
    printf("Sum: %d\n", array_sum(arr, size));   // 80
    printf("Avg: %.2f\n", array_avg(arr, size)); // 16.00

    return 0;
}
