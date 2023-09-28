#include <stdio.h>
#define MAX 20

int intArray[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

int Binsearch(int num){
    int lb = 0;
    int ub = MAX - 1;
    int midPoint = -1;
    int comp = 0;
    int index = -1;
    while (lb <= ub){
        comp++;
        midPoint = (lb + ub)/2; 
        if(intArray[midPoint] == num){
            index = midPoint;
            break;
        } else {
            if(intArray[midPoint] < num){
                lb = midPoint + 1;
            } else {
                ub = midPoint - 1;
            }
        }
    }
    return index;
}



int main(){
    int location = Binsearch(11);
    if(location != -1)
      printf("\nElement found at location: %d" ,(location+1));
   else
      printf("\nElement not found.");
    return 0;
}