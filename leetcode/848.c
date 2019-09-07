#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

char* shiftingLetters(char* S, int* shifts, int shiftsSize) {
    // char ans[shiftsSize];
    // for(int i = 0, j = 0; i < shiftsSize; ++i) {
    //     ans[i] = S[i];
    //     for(j = 0; j <= i; ++j) {
    //         ans[j] = ((ans[j]-'a'+shifts[i])%26) + 'a';
    //     }printf("%s\n", ans);
    // }
    // char* res = (char*)malloc(sizeof(char)*(shiftsSize+1));
    // for(int i = 0; i < shiftsSize; ++i) res[i] = ans[i];
    // res[shiftsSize] = '\0';
    // return res;

    int shift = 0;
    char ans[shiftsSize];
    for(int i = shiftsSize-1; i >= 0; --i) {
        shift = (shift + shifts[i]) % 26;
        ans[i] = ((S[i]-'a'+shift)%26) + 'a';
    }
    char* res = (char*)malloc(sizeof(char)*(shiftsSize+1));
    for(int i = 0; i < shiftsSize; ++i) res[i] = ans[i];
    res[shiftsSize] = '\0';
    return res;
}

int main() {
    int a[] = {39,79,78,15,5,35,97,79};
    int* n = (int*)malloc(sizeof(int)*8);
    for(int i = 0; i < 8; ++i) n[i] = a[i];
    char* s = "sntxbzdr";
    char* ans = shiftingLetters(s, n, strlen(s));
    printf("%s\n", ans);
    // printf("%d\n", INT_MAX);
    return 0;
}