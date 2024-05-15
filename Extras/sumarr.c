#include <stdio.h>

int sumOfArrays(int nums1[], int m, int nums2[], int n) {
    int sum = 0;
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            sum += nums1[i];
            i++;
        } else {
            sum += nums2[j];
            j++;
        }
    }
    while (i < m) {
        sum += nums1[i];
        i++;
    }
    while (j < n) {sum += nums2[j];j++;}
    
    return sum;
}

int main() {
    int nums1[] = {1, 3};
    int m = sizeof(nums1) / sizeof(nums1[0]);

    int nums2[] = {2};
    int n = sizeof(nums2) / sizeof(nums2[0]);

    int result = sumOfArrays(nums1, m, nums2, n);
    printf("Sum of arrays: %d\n", result);

    return 0;
}