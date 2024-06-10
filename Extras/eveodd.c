#include<stdio.h>

int main(){
    int arr[] = {12, 123, 12, 2, 32, 23, 232};
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) printf("%d is %s\n", arr[i], arr[i] % 2 == 0 ? "Even" : "Odd");
    return 0;
}