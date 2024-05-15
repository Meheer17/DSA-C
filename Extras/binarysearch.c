#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
    int mid = (left + right) / 2;
    if (arr[mid] == x)
        return mid;
    if (arr[mid] < x)
        return binarySearch(arr, mid, right, x);
    else
        return binarySearch(arr, left, mid, x);
    return -1;
}

int main() {
    int arr[] = {1, 5, 6, 7, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9;
    int result = binarySearch(arr, 0, n, x);
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at location %d\n", result);
    return 0;
}