#include <stdio.h>

void findFrequency(char *s) {
    int frequency[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) if (s[i] >= 'a' && s[i] <= 'z') frequency[s[i] - 'a']++;
    for (int i = 0; i < 26; i++) if (frequency[i] > 0) printf("%c -> %d\n", 'a' + i, frequency[i]);
}

int main() {
    char s[] = "tree";
    printf("%c\n", 97 );
    findFrequency(s);
    return 0;
}