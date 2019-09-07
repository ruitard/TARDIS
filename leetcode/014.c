#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0 || strs == NULL) return "";
    
    for(int i = 0; i < strlen(strs[0]); i++) {
        char c = strs[0][i]; // printf("%c\n", c);
        for(int j = 0; j < strsSize; j++) {
            if(i == strlen(strs[j]) || strs[j][i] != c) {
                char* prefix = (char*)malloc(sizeof(char)*(i+1));
                // printf("%s\n", prefix);
                for(int k = 0; k < i; k++) {
                    prefix[k] = strs[0][k];
                }
                prefix[i] = '\0';
                return prefix;
            }
        }
    }
    return strs[0];
}

int main() {
    char** strs = (char**)malloc(sizeof(char*)*3);
    strs[0] = "flower";
    strs[1] = "flow";
    strs[2] = "flight";
    printf("%s\n", longestCommonPrefix(strs, 3));
    free(strs[0]);
    free(strs[1]);
    free(strs[2]);
    free(strs);
    return 0;
}