// find missing elements in unsorted array
#include <stdio.h>

void findMissingElements(int arr[], int size, int range) {
    int present[range + 1] = {0};
    for (int i = 0; i < size; i++) present[arr[i]] = 1;
    printf("Missing elements: ");
    for (int i = 1; i <= range; i++) if (present[i] == 0) printf("%d ", i);
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 1, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int range = 6;
    findMissingElements(arr, size, range);
    return 0;
}