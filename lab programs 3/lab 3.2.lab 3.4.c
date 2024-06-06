#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* findStringBeforeLastOperation(char* s) {
    int counts[26] = {0};
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        counts[s[i] - 'a']++;
    }
        int index = s[i] - 'a';
        if (counts[index] > 1) {
            counts[index]--;
        } else {
            memmove(&s[i], &s[i + 1], length - i);
            length--;
            i--;
        }
    }

    return s;
}
int main() {
    char s[] = "aabcbbca";
    printf("%s\n", findStringBeforeLastOperation(s));
    return 0;
}
