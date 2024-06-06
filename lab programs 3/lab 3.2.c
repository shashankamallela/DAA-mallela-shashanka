#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void sortString(char* s, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] > s[j]) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

bool canBreak(char* s1, char* s2, int n) {
    for (int i = 0; i < n; ++i) {
        if (s1[i] < s2[i]) {
            return false;
        }
    }
    return true;
}

bool checkIfCanBreak(char* s1, char* s2, int n) {
    sortString(s1, n);
    sortString(s2, n);
    return canBreak(s1, s2, n) || canBreak(s2, s1, n);
}

int main() {
    char s1[] = "abc";
    char s2[] = "xya";
    int n = strlen(s1);
    printf("%s\n", checkIfCanBreak(s1, s2, n) ? "true" : "false");
    return 0;
}
