#include<stdio.h>

int main(){
    int arr1[2], arr2[2];
    for(int i = 0; i < 2; i++){
        printf("%d-th number (arr - 1) :",i);
        scanf("%d", &arr1[i]);
    }
    for(int i = 0; i < 2; i++){
        printf("%d-th number (arr - 2) :",i);
        scanf("%d", &arr2[i]);
    }
    int size = sizeof(arr1) / sizeof(arr1[0]), size2 = sizeof(arr2) / sizeof(arr2[0]);
    int newarr[size + size2];
    int i = 0;
    for(i; i < size; i++) {newarr[i] = arr1[i]; printf("%d\n", newarr[i]);}
    for(i; i - size < size2; i++) {newarr[i - size] = arr2[i - size]; printf("%d\n", newarr[i - size]);}
    return 0;
}