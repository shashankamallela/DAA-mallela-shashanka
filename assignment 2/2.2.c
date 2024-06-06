#include <stdio.h>
#include <string.h>
int value(char r) {
    switch (r) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;
    }
}
int romanToDecimal(char* str) {
    int res = 0;
    int i = 0;
    int len = strlen(str);

    while (i < len) {
        int s1 = value(str[i]);

        if (i + 1 < len) {
            int s2 = value(str[i + 1]);
            if (s1 >= s2) {
                res = res + s1;
                i = i + 1;
            } else {
                res = res + s2 - s1;
                i = i + 2;
            }
        } else {
            res = res + s1;
            i = i + 1;
        }
    }
    return res;
}
int main() {
    char roman[] = "MCMIV";
    printf("Integer form of Roman Numeral is %d\n", romanToDecimal(roman));
    return 0;
}
