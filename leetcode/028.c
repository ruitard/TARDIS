#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
int strStr(char* haystack, char* needle) {
    if(haystack == NULL) return -2;
    if(needle == "") return 0;
    int h_len = strlen(haystack);
    int len = strlen(needle);
    // if(h_len < len) return -1;
    int j = 0;
    int i = 0;
    int max = (strlen(haystack)-len);
    for(i = 0; i <= max; i++) {

        printf("%d %d\n", strlen(haystack)-len, h_len-len);
        printf("%d\n", i);
        for(j = 0; j < len; ++j) {
            if(needle[j] != haystack[i+j]) {
                goto label;
            }
        }
        return i;
        label:;
    }
    return -1;
}
 */

int strStr(char* haystack, char* needle) {
    int slen = strlen(haystack);
    int plen = strlen(needle);
    if(slen < plen) return -1;
    if(plen == 0) return 0;
    int next[plen];
    next[0] = -1;
    if(plen > 1) next[1] = 0;
    int i = 1;
    int j = 0;
    while(i < plen-1) {
        if(j == -1 || needle[j] == needle[i]) {
            ++j;
            ++i;
            next[i] = j;
        }
        else j = next[j];
    }
    i = 0;
    j = 0;
    while(i < slen && j < plen) {
        if(j == -1 || haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else j = next[j];
    }
    if(j == plen) return i - plen;
    else return -1;
}

int main(int argc, char* args[]) {
    // char* s = "aaabaaabbbabaa";
    // char* p = "babb";
    printf("%d\n", strStr(args[1], args[2]));
    return 0;
}