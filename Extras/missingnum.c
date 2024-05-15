#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        int found = 0;
        for (j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return n + 1;
}

int main() {
    int arr[] = {2, 3, 7, 6, 8, -1, -10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int missingNumber = findMissingNumber(arr, n);
    printf("The smallest positive number missing from the array is: %d\n", missingNumber);
    return 0;
}