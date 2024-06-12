#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int mergedArr[]) {
    int i, j, k;
    
    // Copy elements of arr1 to mergedArr
    for (i = 0; i < size1; i++) {
        mergedArr[i] = arr1[i];
    }
    
    // Copy elements of arr2 to mergedArr
    for (j = 0, k = size1; j < size2; j++, k++) {
        mergedArr[k] = arr2[j];
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {6, 7, 8, 9, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int mergedArr[size1 + size2];
    
    mergeArrays(arr1, size1, arr2, size2, mergedArr);
    
    printf("Merged Array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedArr[i]);
    }
    
    return 0;
}