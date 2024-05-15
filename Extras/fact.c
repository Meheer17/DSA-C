#include <stdio.h>

int main() {
    int N, factorial = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is %d\n", N, factorial);
    return 0;
}