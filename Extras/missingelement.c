#include <stdio.h>

int findMissingElement(int arr[], int N) {
    int totalSum = (N * (N + 1)) / 2;
    int arraySum = 0; 

    for (int i = 0; i < N - 1; i++) {
        arraySum += arr[i];
    }
    
    return totalSum - arraySum;
}

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    
    int arr[N-1];
    printf("Enter the array elements: ");
    for (int i = 0; i < N-1; i++) {
        scanf("%d", &arr[i]);
    }
    
    int missingElement = findMissingElement(arr, N);
    printf("The missing element is: %d\n", missingElement);
    
    return 0;
}
