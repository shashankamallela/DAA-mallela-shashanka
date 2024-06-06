#include <stdio.h>
#include <string.h>

struct Pair {
    int first;
    int second;
};
char* longestPalindrome(const char* s) {
    if (s[0] == '\0')
        return "";

    struct Pair indices = {0, 0};
    int i, l1, r1, l2, r2;
    int length = strlen(s);

    for (i = 0; i < length; ++i) {
        l1 = i;
        r1 = i;
        while (l1 >= 0 && r1 < length && s[l1] == s[r1]) {
            --l1;
            ++r1;
        }
        if (r1 - l1 > indices.second - indices.first) {
            indices.first = l1 + 1;
            indices.second = r1 - 1;
        }

        if (i + 1 < length && s[i] == s[i + 1]) {
            l2 = i;
            r2 = i + 1;
            while (l2 >= 0 && r2 < length && s[l2] == s[r2]) {
                --l2;
                ++r2;
            }
            if (r2 - l2 > indices.second - indices.first) {
                indices.first = l2 + 1;
                indices.second = r2 - 1;
            }
        }
    }
    char* result = malloc(indices.second - indices.first + 2);
    strncpy(result, s + indices.first, indices.second - indices.first + 1);
    result[indices.second - indices.first + 1] = '\0';
    return result;
}

int main() {
    const char* s = "babad";
    printf("Longest palindrome: %s\n", longestPalindrome(s));
    return 0;
}
