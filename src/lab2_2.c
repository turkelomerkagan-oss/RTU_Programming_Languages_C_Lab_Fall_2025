#include <stdio.h>

// Function that calculates factorial of n
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (n < 0) {
        printf("Error: n must be >= 0\n");
    } else {
        long long fact = factorial(n);
        printf("%d! = %lld\n", n, fact);
    }

    return 0;
}
#include <stdio.h>

// Function that calculates factorial of n
long long factorial(int n) {
  long long result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Error: n must be >= 0\n");
  } else {
    long long fact = factorial(n);
    printf("%d! = %lld\n", n, fact);
  }

  return 0;
}
