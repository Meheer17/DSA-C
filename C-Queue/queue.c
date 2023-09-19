#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct{
    int length;
    unsigned char num[];
} List;

typedef struct {
    int first, last;
    List l;
} Queue;

int main(){
    Queue *s = (Queue *)malloc(sizeof(Queue));
    insert(s, 0, 10);
    insert(s, 0, 20);
    view_queue(s);
    fl_queue(s);
    pop(s);
    view_queue(s);
    fl_queue(s);
    return 0;
};