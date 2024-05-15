#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL, *current = NULL, *newNode = NULL;

struct Node* createNode(int data){
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(int data){
    newNode = createNode(data);

    if(head == NULL){
        head = newNode;
        head->next = head;
        head->prev = head;
    }else{
        current = head;
        while(current->next != head){
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        newNode->next = head;
        head->prev = newNode;
    }
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        current = head;
        do{
            printf("%d ", current->data);
            current = current->next;
        }while(current != head);
    }
}

void insertAtBeginning(int data){
    newNode = createNode(data);

    if(head == NULL){
        head = newNode;
        head->next = head;
        head->prev = head;
    }else{
        current = head;
        while(current->next != head){
            current = current->next;
        }
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = current;
        current->next = newNode;
        head = newNode;
    }
}

void rem(int data){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        current = head;
        struct Node *prevNode = NULL;
        do{
            if(current->data == data){
                if(current == head){
                    head = head->next;
                }else{
                    prevNode->next = current->next;
                    current->next->prev = prevNode;
                }
                free(current);
                return;
            }
            prevNode = current;
            current = current->next;
        }while(current != head);
        printf("Data not found\n");
    }
}

void removeAtBeginning(){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        current = head;
        if(current->next == head){
            head = NULL;
        }else{
            head = head->next;
            head->prev = current->prev;
            current->prev->next = head;
        }
        free(current);
    }
}

void removeAnywhere(int index){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        current = head;
        struct Node *prevNode = NULL;
        int i = 0;
        do{
            if(i == index){
                if(current == head){
                    head = head->next;
                }else{
                    prevNode->next = current->next;
                    current->next->prev = prevNode;
                }
                free(current);
                return;
            }
            prevNode = current;
            current = current->next;
            i++;
        }while(current != head);
        printf("Index not found\n");
    }
}

void search(int num){
    if(head == NULL){
        printf("List is empty\n");
    }else{
        current = head;
        int i = 0;
        do{
            if(current->data == num){
                printf("Data found at index %d\n", i);
                return;
            }
            current = current->next;
            i++;
        }while(current != head);
        printf("Data not found\n");
    }
}

int main(){
    // call all the functions here
    insert(5);
    insert(10);
    insert(15);
    display();
    printf("\n");
    insertAtBeginning(20);
    display();
    printf("\n");
    rem(10);
    display();
    printf("\n");
    removeAtBeginning();
    display();
    printf("\n");
    removeAnywhere(1);
    display();
    printf("\n");
    search(15);
    
    return 0;
}