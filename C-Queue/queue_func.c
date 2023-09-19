#include "queue.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int length;
    unsigned char num[];
} List;

typedef struct {
    int first, last;
    List l;
} Queue;

int len(Queue *arr)
{
    return arr->l.length;
};

void insert(Queue *arr, int num, int value)
{
    int tmp = arr->l.num[num];
    arr->l.num[num] = value;
    int i = num;
    while(i < arr->l.length + 1){
        int sec = arr->l.num[i+1];
        arr->l.num[i+1] = tmp;
        tmp = sec;
        i++;
    }
    arr->l.length++;
}

void fl_queue(Queue *arr){
    if(arr->l.length - 1 == -1) {
        printf("The Queue is empty");
    } else {
        arr->first = arr->l.num[0];
        arr->last = arr->l.num[arr->l.length-1];
        printf("The number of elements is %d and the first element is %d and last is %d\n", arr->l.length, arr->first, arr->last);
    }
}

int pop(Queue *arr)
{   
    if(arr->l.length - 1 == -1) return -1;
    int item = arr->l.num[arr->l.length-1];
    arr->l.num[arr->l.length - 1] = 0;
    (arr->l.length)--;
    return item;
};

void view_queue(Queue *s) 
{
    printf("[");
    for(int i = s->l.length; i > 0 ; i--) printf(" %d, ", s->l.num[i-1]);
    printf("]\n");
}