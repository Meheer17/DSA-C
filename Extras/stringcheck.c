#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1) {
                return false;
            } else if ((s[i] == ')' && stack[top] == '(') || (s[i] == '}' && stack[top] == '{') || (s[i] == ']' && stack[top] == '[')) {
                top--;
            } else {
                return false;
            }
        }
    }
    
    return top == -1;
}

int main() {
    char s[] = "{[]}";
    
    if (isValid(s)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    
    return 0;
}