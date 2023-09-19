#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct{
    int length;
    unsigned char num[];
} List;

typedef struct {
    int top;
    List l;
} Stack;

int main(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    push(s, 10);
    push(s, 20);
    push(s, 50);
    view_stack(s);
    top_stack(s);
    pop(s);
    view_stack(s);
    top_stack(s);
    return 0;
};