#include <stdio.h>

// Function that calculates sum from 1 to n
int sum_to_n(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (n < 1) {
        printf("Error: n must be >= 1\n");
    } else {
        int result = sum_to_n(n);
        printf("Sum from 1 to %d = %d\n", n, result);
    }

    return 0;
}
#include <stdio.h>

int sum_to_n(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Error: n must be >= 1\n");
    } else {
        int result = sum_to_n(n);
        printf("Sum from 1 to %d = %d\n", n, result);
    }

    return 0;
}
