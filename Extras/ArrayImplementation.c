#include<stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

void createArray(int elements[], int n) {
    if (n > MAX_SIZE) {
        printf("Array size exceeds maximum limit.\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = elements[i];
    }
    
    size = n;
    printf("Array created successfully.\n");
}

void insertElement(int element, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position.\n");
        return;
    }
    
    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    
    for (int i = size - 1; i >= position; i--) arr[i + 1] = arr[i];
    arr[position] = element;
    size++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = position; i < size - 1; i++) arr[i] = arr[i + 1];
    size--;
    printf("Element deleted successfully.\n");
}

void displayArray() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    
    printf("Array elements: [ ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf(" ]\n");
}

int linearSearch(int element) {
    for (int i = 0; i < size; i++) if (arr[i] == element) return i;
    return -1;
}

int binarySearch(int element) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == element) return mid;

        if (arr[mid] < element) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void reverseArray() {
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
    
    printf("Array reversed successfully.\n");
}
int main() {
    int ch = 1;
    int elements[MAX_SIZE], size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &elements[i]);
    }
    createArray(elements, size);
    
    while (ch != 0) {
        printf("Enter your choice:\n1. Insert element\n2. Delete element\n3. Display array\n4. Linear search\n5. Binary search\n6. Reverse array\n0. Exit\n");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                int element, position;
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertElement(element, position);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteElement(position);
                break;
            case 3:
                displayArray();
                break;
            case 4:
                int elementToSearch, linearSearchIndex;
                printf("Enter the element to search: ");
                scanf("%d", &elementToSearch);
                linearSearchIndex = linearSearch(elementToSearch);
                if (linearSearchIndex != -1) {
                    printf("Element %d found at index %d (linear search).\n", elementToSearch, linearSearchIndex);
                } else {
                    printf("Element %d not found (linear search).\n", elementToSearch);
                }
                break;
            case 5:
                int binarySearchIndex;
                printf("Enter the element to search: ");
                scanf("%d", &elementToSearch);
                binarySearchIndex = binarySearch(elementToSearch);
                if (binarySearchIndex != -1) {
                    printf("Element %d found at index %d (binary search).\n", elementToSearch, binarySearchIndex);
                } else {
                    printf("Element %d not found (binary search).\n", elementToSearch);
                }
                break;
            case 6:
                reverseArray();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}