#include <stdio.h>
#include <stdbool.h>

#define MAX 7
int intArray[MAX] = {4,6,3,2,1,9,7};

void display(){
   int i;
   printf("[");
   for(i=0;i<MAX;i++){
      printf("%d ",intArray[i]);
   }
   printf("]\n");
}   

void insertionSort(){
   int valueToInsert;
   int holePosition;
   int i;
   // loop through all numbers 
   for(i=1; i < MAX; i++){ 
        valueToInsert = intArray[i];
        holePosition = i;
        while (holePosition > 0 && intArray[i-1] > valueToInsert){
            intArray[holePosition] = intArray[holePosition-1];
            holePosition--;
            printf(" item moved : %d\n" , intArray[holePosition]);
        }
    
        if(holePosition!= i){
            printf(" item inserted : %d, at position : %d\n", valueToInsert, holePosition);		  
            intArray[holePosition] = valueToInsert;   
        }
        printf("Iteration %d#:",i);
        display();
   }  
}

void main(){
   printf("Input Array: ");
   display();
   insertionSort();
   printf("Output Array: ");
   display();
}