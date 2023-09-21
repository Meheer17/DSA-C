
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *prev = NULL;
struct node *current = NULL;

int isEmpty(){
    if (head == NULL) return 1;
    return 0;
}

void display(){
    current = head;
    printf("[");
    while(current->next != NULL){
        current = current->next;
        printf("%d ", current->data);    
    }
    printf("%d ]\n", current->data);    
    return;
}

void insert(int num){
    struct node *p = (struct node*) malloc(sizeof(struct node));
    if(isEmpty()){
        head = p;
        p->data = num;
        p->next = NULL;
        p->prev = NULL;
    } else {
        current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = p;
        p->data = num;
        p->prev = current;
        p->next = NULL;
    }
}

void insert_middle(int num, int ind){
    struct node *p = (struct node*) malloc(sizeof(struct node));
    current = head;
    int count = 0;
    prev = current;
    while(current->next != NULL && count < ind+1){
        prev = current;
        current = current->next;
        count++;
    }
    p->next = prev->next;
    prev->next = p;
    p->data = num;
    p->prev = prev;
    current->prev = p;
}

void rem(){
    current = head;
    prev = current;
    while(current->next != NULL){
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

void remove_index(int ind){
    current = head;
    prev = current;
    int count = 0;
    while(current->next != NULL && count < ind + 1){
        prev = current;
        current = current->next;
        count++;
    }
    prev->next = current->next;
    (current->next)->prev = prev;
    free(current);
}

int main(){
    insert(10);
    insert(10);
    insert(10);
    insert(10);
    insert(10);
    insert(10);
    insert_middle(11, 2);
    display();
    remove_index(2);
    display();
    insert(10);
    display();
    rem();
    display();
    return 0;
}
