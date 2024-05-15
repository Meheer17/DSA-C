#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void add(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void addtoindex(int data, int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* current = head;
        int i = 0;
        while (current != NULL && i < index - 1) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            printf("Invalid index\n");
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void addtostart(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void delete(int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

void deleteindex(int index) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (index == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int i = 0;
    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Invalid index\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

void deletestart() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void display() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    add(1);
    add(2);
    add(3);
    addtoindex(4, 1);
    addtostart(5);
    delete(2);
    deleteindex(1);
    deletestart();
    display();

    return 0;
}