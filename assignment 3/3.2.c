#include <stdio.h>
#include <string.h>

void stringShift(char* s, int shift[][2], int shiftSize) {
    int val = 0;
    int Len = strlen(s);
    for (int i = 0; i < shiftSize; i++) {
        if (shift[i][0] == 0) {
            val -= shift[i][1]; 
        } else {
            val += shift[i][1]; 
        }
    }
    val = val % Len;
    char result[Len + 1];
    result[Len] = '\0';
    if (val > 0) {
        strncpy(result, s + Len - val, val);
        strncpy(result + val, s, Len - val);
    }
    else {
        val = -val;
        strncpy(result, s + val, Len - val);
        strncpy(result + Len - val, s, val);
    }

    printf("%s\n", result);
}

int main() {
    char s[] = "abc";
    int shift[][2] = {
        {0, 1},
        {1, 2}
    };
    int shiftSize = sizeof(shift) / sizeof(shift[0]);

    stringShift(s, shift, shiftSize);

    return 0;
}



