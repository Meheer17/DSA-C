#include <stdio.h>

int fibonacci(int n);
int fibonacciSum(int n);

int main() {
    int n = 10;
    printf("Fibonacci series:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\nSum: %d\n", fibonacciSum(n));
    return 0;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciSum(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += fibonacci(i);
    }
    return sum;
}