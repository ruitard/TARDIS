#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    unsigned int* pos = calloc(128, sizeof(unsigned int));
    if (s[0] == '\0') return 0;
    unsigned int i = 0, j = 1, ans = 1;
    pos[(size_t)s[0]] = 1;
    while (s[j]) {
        if (pos[(size_t)s[j]] <= i) {
            pos[(size_t)s[j]] = j + 1;
        } else {
            ans = ans>=(j-i) ? ans : (j-i);
            i = pos[(size_t)s[j]];
            pos[(size_t)s[j]] = j + 1;
        }
        j++;
    }
    ans = ans>=(j-i) ? ans : (j-i);
    free(pos);
    return ans;
}

int main() {
    printf("%d %d %d\n", lengthOfLongestSubstring("aaa"), lengthOfLongestSubstring("bbbb"),
        lengthOfLongestSubstring("pwwkew"));
        printf("%d %d %d\n", lengthOfLongestSubstring("abcabcbb"), lengthOfLongestSubstring(" "),
        lengthOfLongestSubstring("  "));
    return 0;
}