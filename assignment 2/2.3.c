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
int romanToInt(const char* S) {
    int sum = 0;
    int len = strlen(S);

    for (int i = len - 1; i >= 0; i--) {
        int num = value(S[i]);
        if (3 * num < sum) {
            sum -= num;
        } else {
            sum += num;
        }
    }
    return sum;
}
int main() {
    char roman[] = "MCMIV";
    printf("Integer form of Roman Numeral is %d\n", romanToInt(roman));
    return 0;
}
