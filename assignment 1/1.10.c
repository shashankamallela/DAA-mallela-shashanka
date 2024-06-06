#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int isPalindrome(const char* s, int l, int r) {
    if (l < 0)
        return 0;
    while (l < r) {
        if (s[l++] != s[r--])
            return 0;
    }
    return 1;
}

int maxPalindromes(const char* s, int n, int k) {
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = k; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (isPalindrome(s, i - k, i - 1))
            dp[i] = max(dp[i], 1 + dp[i - k]);
        if (isPalindrome(s, i - k - 1, i - 1))
            dp[i] = max(dp[i], 1 + dp[i - k - 1]);
    }
    return dp[n];
}

int main() {
    const char* s = "ababa";
    int k = 3;
    int n = strlen(s);
    printf("Maximum palindromes: %d\n", maxPalindromes(s, n, k));
    return 0;
}
