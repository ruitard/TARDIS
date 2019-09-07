#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numDecodings(char* s) {
    size_t len = strlen(s);
    int* A = (int*)malloc(sizeof(int)*len);
    if(s[0] != '0') {
        A[0] = 1;
    }
    if(len^1 == 0) return A[0];
    for(int i = 1; i < len; ++i) {
        A[i] = 0;
        if(s[i] != '0') A[i] += A[i-1];
        if((s[i-1] == '1') || ((s[i-1]=='2') && (s[i]>='0') && (s[i]<='6'))) {
            A[i] = i^1 == 0 ? A[i] : A[i] + A[i-2];
        }
    }
    return A[len-1];
}

int main() {
    char* s = "222";
    printf("%d\n", numDecodings(s));
    return 0;
}