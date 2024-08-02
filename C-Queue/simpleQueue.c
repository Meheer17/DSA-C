#include<stdio.h>

int arr[100];
int rear = 0, front = 0;

void enque(int num){
    arr[rear] = num;
    rear++;
}

void deque(){
    arr[front] = 0;
    front++;
}

void printqueue(){
    printf("[ ");
    for(int i = front; i < rear; i++) printf(" %d ", arr[i]); 
    printf(" ]\n");
}

int main(){
    enque(10);
    enque(20);
    printqueue();
    deque();
    printqueue();
}