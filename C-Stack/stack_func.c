#include "stack.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int length;
    unsigned char num[];
} List;

typedef struct {
    int top;
    List l;
} Stack;

int len(Stack *arr)
{
    return arr->l.length;
};

void push(Stack *arr, long long value)
{
    arr->l.num[arr->l.length] = value;
    (arr->l.length)++;
};

int pop(Stack *arr)
{   
    if(arr->l.length - 1 == -1) return 0
    int item = arr->l.num[arr->l.length-1];
    arr->l.num[arr->l.length - 1] = 0;
    (arr->l.length)--;
    return item;
};

int top_stack(Stack *s)
{
    if(s->l.length - 1 == -1){ printf("The Stack Is Empty"); return -1; } 
    else {
        s->top = s->l.length - 1;
        printf("%d\n", s->l.num[s->top]);
        return s->l.num[s->top];
    }
}

void view_stack(Stack *s){
    printf("[");
    for(int i = 0; i < s->l.length; i++) printf(" %d, ", s->l.num[i]);
    printf("]\n");
}