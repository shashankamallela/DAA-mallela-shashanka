#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isMatch(const char* s, const char* p) {
    int m = strlen(s);
    int n = strlen(p);
    bool dp[m + 1][n + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for (int j = 0; j < n; ++j) {
        if (p[j] == '*' && dp[0][j - 1]) {
            dp[0][j + 1] = true;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (p[j] == '*') {
                bool noRepeat = dp[i + 1][j - 1];
                bool doRepeat = (i >= 0 && j >= 0) && ((p[j - 1] == '.' || s[i] == p[j - 1]) && dp[i][j + 1]);
                dp[i + 1][j + 1] = noRepeat || doRepeat;
            } else if ((j >= 0) && ((p[j] == '.' || s[i] == p[j]) && dp[i][j])) {
                dp[i + 1][j + 1] = true;
            }
        }
    }

    return dp[m][n];
}
int main() {
    const char* s = "mississippi";
    const char* p = "mis*is*p*.";
    if (isMatch(s, p))
        printf("The strings match.\n");
    else
        printf("The strings do not match.\n");
    return 0;
}
