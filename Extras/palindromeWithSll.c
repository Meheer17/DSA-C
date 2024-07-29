#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    char data;
    struct Node* next;
};

// Function to check if a linked list is a palindrome
int isPalindrome(struct Node* head) {
    // Create a new list with the reverse of the existing list
    struct Node* reverse = NULL;
    struct Node* current = head;
    while (current != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = current->data;
        newNode->next = reverse;
        reverse = newNode;
        current = current->next;
    }

    // Compare the two lists
    while (head != NULL && reverse != NULL) {
        if (head->data != reverse->data) {
            return 0; // Not a palindrome
        }
        head = head->next;
        reverse = reverse->next;
    }

    return 1; // Palindrome
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to create a new node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Driver code
int main() {
    // Create a linked list
    struct Node* head = newNode('r');
    head->next = newNode('a');
    head->next->next = newNode('d');
    head->next->next->next = newNode('a');
    head->next->next->next->next = newNode('r');

    printf("Original list: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}