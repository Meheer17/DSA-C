#include <stdio.h>
#include <string.h>

void sortString(char* s) {
    int count[256] = {0};
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        count[s[i]]++;
    }

    int index = 0;
    for (int i = 0; i < 256; i++) {
        while (count[i] > 0) {
            s[index++] = i;
            count[i]--;
        }
    }
    s[index] = '\0';
}

void findRepeatedCharIndex(char* s) {
    int length = strlen(s);
    int index[length];
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] == s[i + 1]) {
            index[count++] = i;
        }
    }

    printf("Sorted string: %s\n", s);
    printf("Starting index of repeated characters: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", index[i]);
    }
    printf("\n");
}

int main() {
    char s[] = "HelloTHERE";
    sortString(s);
    findRepeatedCharIndex(s);

    return 0;
}