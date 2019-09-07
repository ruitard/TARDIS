#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool buddyStrings(char* A, char* B) {
    size_t len = strlen(A);
    if(len != strlen(B)) return false;
    if(A == B) {
        size_t* alphabet = calloc(sizeof(size_t), 26);
        size_t index;
        for(size_t i = 0; i < len; i++) {
            index = A[i] - 'a';printf("%d\n", index);
            if(++alphabet[index] == 2) return true;
        }
        return false;
    }
    size_t count = 0;
    size_t mask[2];
    for(size_t i = 0; i < len; i++) {
        if(A[i] != B[i]) {
            if(count == 2) return false;
            mask[count] = i;
            count++;
        }
    }printf("%d %d\n", mask[0], mask[1]);
    if(count == 1) {
        return false;
    }
    if((A[mask[0]] == B[mask[1]]) && (A[mask[1]] == B[mask[0]])) return true;
    else return false;
}

int main(void) {
    char* s1 = "aa";
    char* s2 = "aa";
    printf("%s %s %d\n", s1, s2, buddyStrings(s1, s2));
    return 0;
}