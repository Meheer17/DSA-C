#include<stdio.h>

int revNum(int x){
    static int y = 0;
    y = (y * 10) + (x % 10);
    return x > 10 ? revNum(x / 10) : y;  
}

int main(){
    printf("%d\n", revNum(123));
    return 0;
}