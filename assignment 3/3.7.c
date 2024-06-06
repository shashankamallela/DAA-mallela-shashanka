#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maxDiff(int num) {
    char a[12], b[12];
    snprintf(a, sizeof(a), "%d", num);
    snprintf(b, sizeof(b), "%d", num);

    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] != '9') {
            char old_char = a[i];
            for (int j = 0; a[j] != '\0'; j++) {
                if (a[j] == old_char) {
                    a[j] = '9';
                }
            }
            break;
        }
    }
    if (b[0] != '1') {
        char old_char = b[0];
        for (int i = 0; b[i] != '\0'; i++) {
            if (b[i] == old_char) {
                b[i] = '1';
            }
        }
    } else {
        for (int i = 1; b[i] != '\0'; i++) {
            if (b[i] != '0' && b[i] != '1') {
                char old_char = b[i];
                for (int j = 0; b[j] != '\0'; j++) {
                    if (b[j] == old_char) {
                        b[j] = '0';
                    }
                }
                break;
            }
        }
    }

    return atoi(a) - atoi(b);
}

int main() {
    int num = 123456;
    printf("Max difference: %d\n", maxDiff(num));
    return 0;
}



