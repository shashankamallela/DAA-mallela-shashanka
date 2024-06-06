#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* longestCommonPrefix(char** a, int size) {
    if (size == 0) {
        return "";
    }
    if (size == 1) {
        return a[0];
    }
    int end = (strlen(a[0]) < strlen(a[size - 1])) ? strlen(a[0]) : strlen(a[size - 1]);
    int i = 0;
    while (i < end && a[0][i] == a[size - 1][i]) {
        i++;
    }
    char* pre = (char*)malloc((i + 1) * sizeof(char));
    strncpy(pre, a[0], i);
    pre[i] = '\0';
    return pre;
}
int main() {
    char* input[] = {"geeksforgeeks", "geeks", "geek", "geezer"};
    int size = sizeof(input) / sizeof(input[0]);
    char* result = longestCommonPrefix(input, size);
    printf("The longest Common Prefix is: %s\n", result);
    free(result); 
    return 0;
}
