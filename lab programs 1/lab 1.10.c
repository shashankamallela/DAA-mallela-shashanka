#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isPalRec(const char* str, int s, int e) {
    if (s == e)
        return true;
    if (str[s] != str[e])
        return false;
    if (s < e + 1)
        return isPalRec(str, s + 1, e - 1);
    return true;
}
bool isPalindrome(const char* str) {
    int n = strlen(str);
    if (n == 0)
        return true;
    return isPalRec(str, 0, n - 1);
}
int main() {
    const char* str = "geeg";

    if (isPalindrome(str))
        printf("Yes");
    else
        printf("No");

    return 0;
}
