#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(const char* s) {
    int ans = 0;
    int count[128] = {0}; 

    for (int l = 0, r = 0; s[r] != '\0'; ++r) {
        ++count[s[r]];
        while (count[s[r]] > 1)
            --count[s[l++]];
        ans = (r - l + 1) > ans ? (r - l + 1) : ans;
    }
    return ans;
}
int main() {
    const char* s = "abcabcbb";
    printf("Length of the longest substring without repeating characters: %d\n", lengthOfLongestSubstring(s));
    return 0;
}
