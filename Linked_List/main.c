#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

int isEmpty() { if(head == NULL) return 1; else return 0; }

void printList(){
    if (!isEmpty()){
        struct node *p = head;
        printf("\n[");

        //start from the beginning
        while(p != NULL) {
            printf(" %d ",p->data);
            p = p->next;
        }
        printf("]");
    } else return;
}

void add(int num){
    struct node *p = (struct node*) malloc(sizeof(struct node));
    p->data = num;
    if(isEmpty()){
            head = p;
            head->next = NULL;
    } else {
        current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = p;
        p->next = NULL;
    }
}

void add_first(int num){
    struct node *p = (struct node*) malloc(sizeof(struct node));
    p->data = num;
    if(isEmpty()){
        head = p;
        head->next = NULL;
    } else {
        p->next = head;
        head = p;
    }
}

void add_index(int num, int ind){
    struct node *p = (struct node*) malloc(sizeof(struct node));
    p->data = num;
    if(isEmpty()){
        printf("Empty...");
    } else {
        int count = 0;
        current = head;
        struct node *prev;
        while(current->next != NULL && count < ind){
            prev = current;
            current = current->next;
            count++;
        }
        if(count != ind){
            printf("Try a lesser index...");
        } else if(current->next != NULL){
            p->next = prev->next;
            prev->next = p; 
        } else {
            p->next = NULL;
            prev->next = p;
        }
    }
}

void remove_index(int ind){
    if(isEmpty()){
        printf("Empty...");
    } else {
        int count = 0;
        current = head;
        struct node *prev;
        while(current->next != NULL && count < ind){
            prev = current;
            current = current->next;
            count++;
        }
        if(current->next != NULL){
            prev->next = current->next; 
        } else {
            prev->next = NULL;
        }
    }
}

void remove_end () {
    if(isEmpty()){
        printf("Empty...");
    } else {
        current = head;
        struct node *prev;
        while(current->next != NULL){
            prev = current;
            current = current->next;
        }
        if (current == head) head = NULL;
        prev->next = NULL;
    }   
}

void remove_start () {
    if(isEmpty()){
        printf("Empty...");
    } else {
        if(head->next != NULL){
            head = head->next;
        } else {
            head = NULL;
        }
    }   
}

void count(){
    if (!isEmpty()){
        current = head;
        int count = 1;
        while(current->next != NULL) {
            count++;
            current = current->next;
        }
        printf("\nThe number of elements are: %d", count);
    } else return;
}

void search(int num){
    if(!isEmpty()){
        current = head;
        int i = 0;
        while(current->next != NULL || current->next == NULL){
            if(current->data == num){
                printf("\nThe element was found at %d", i);
                return;
            }
            i++, current = current->next;
        }
        printf("The Element wasn't found!");
    }
    return;
}

int main(){

    add(11);
    add(12);
    add(13);
    add(14);
    printList();
    search(14);
    remove_end();
    count();
    remove_index(1);
    add_first(15);
    add_index(23,2);
    printList();

    return 0;
}