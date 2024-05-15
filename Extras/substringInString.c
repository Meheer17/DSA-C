#include <stdio.h>
#include <string.h>

int findSubstringIndex(const char* haystack, const char* needle) {
    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    for (int i = 0; i <= haystackLen - needleLen; i++) {
        int j;
        for (j = 0; j < needleLen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needleLen) {
            return i;
        }
    }

    return -1;
}

int main() {
    const char* haystack = "sadbutsad";
    const char* needle = "sad";
    int index = findSubstringIndex(haystack, needle);
    printf("Index: %d\n", index);

    haystack = "leetcode";
    needle = "leeto";
    index = findSubstringIndex(haystack, needle);
    printf("Index: %d\n", index);

    return 0;
}