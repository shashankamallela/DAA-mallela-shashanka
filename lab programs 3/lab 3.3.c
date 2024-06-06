#include <stdio.h>
#include <limits.h>

int calculate_value(char *t) {
    int counts[26] = {0};
    int cost = 0;
    for (int i = 0; t[i] != '\0'; i++) {
        cost += counts[t[i] - 'a'];
        counts[t[i] - 'a']++;
    }
    return cost;
}

int dfs(char *s, int i) {
    if (s[i] == '\0') {
        return 0;
    }

    if (s[i] != '?') {
        return dfs(s, i + 1);
    }

    int min_cost = INT_MAX;
    for (char c = 'a'; c <= 'z'; c++) {
        s[i] = c;
        min_cost = (min_cost < (calculate_value(s) + dfs(s, i + 1))) ? min_cost : (calculate_value(s) + dfs(s, i + 1));
        s[i] = '?';
    }

    return min_cost;
}

int minimizeCost(char *s) {
    return dfs(s, 0);
}

int main() {
    char s[] = "a?b?c";
    printf("%d\n", minimizeCost(s));
    return 0;
}
