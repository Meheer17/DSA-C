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

    int choice;
    while (1) {
        printf("\n\nMenu:\n");
        printf("1. Add element\n2. Add element at the beginning\n3. Add element at a specific index\n4. Remove element at a specific index\n5. Remove element from the end\n6. Remove element from the beginning\n7. Search for an element\n8. Print the list\n9. Count the number of elements\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                int num;
                scanf("%d", &num);
                add(num);
                break;
            case 2:
                printf("Enter the element to add at the beginning: ");
                int num2;
                scanf("%d", &num2);
                add_first(num2);
                break;
            case 3:
                printf("Enter the element to add: ");
                int num3;
                scanf("%d", &num3);
                printf("Enter the index to add at: ");
                int index;
                scanf("%d", &index);
                add_index(num3, index);
                break;
            case 4:
                printf("Enter the index to remove: ");
                int index2;
                scanf("%d", &index2);
                remove_index(index2);
                break;
            case 5:
                remove_end();
                break;
            case 6:
                remove_start();
                break;
            case 7:
                printf("Enter the element to search: ");
                int num4;
                scanf("%d", &num4);
                search(num4);
                break;
            case 8:
                printList();
                break;
            case 9:
                count();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}