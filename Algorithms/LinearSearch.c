#include <stdio.h>

#define MAX 50
int intArray[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

int ls(int num){
    int comparisons = 0;
    int index= -1;
    int i = 0;
    while(i < MAX) {
        comparisons++;
        if(num == intArray[i]){
            index = i;
            break;
        }
        i++;
    }
    if(index == -1) printf("Not Found");
    else printf("Found at %d\n", index);
    return index;
}

int main(){
    ls(12);
    return 0;
}