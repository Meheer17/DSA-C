#include<stdio.h>

int main(){
    int arr[] = {1, 2, 3, 5, 5, 2};
    printf("Duplicates: [");
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] == -1) continue;
        for(int j = i + 1; j < sizeof(arr)/sizeof(arr[0]); j++){
            if(arr[i] == arr[j]) {
                printf("%d, ", arr[i]);
                arr[j] = -1;
            };
        }
    }
    printf("]\n");
    return 0;
}