#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}
int arePermutation(char *str1, char *str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if (n1 != n2)
        return 0;
    qsort(str1, n1, sizeof(char), compare);
    qsort(str2, n2, sizeof(char), compare);
    for (int i = 0; i < n1; i++) {
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}
int main() {
    char str1[] = "test";
    char str2[] = "ttew";

    if (arePermutation(str1, str2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
