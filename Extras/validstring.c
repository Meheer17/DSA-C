#include <stdio.h>
#include <ctype.h>

int isValidString(char *str) {
    if (str == NULL || *str == '\0') return 0; 

    while (*str != '\0') {
        if (!isalnum(*str)) return 0;
        str++;
    }
    return 1;
}

int main() {
    char input[100] = "fdg @h234";
    printf("%s\n", isValidString(input) == 1 ? "The string is valid" : "The string is not valid");
    return 0;
}