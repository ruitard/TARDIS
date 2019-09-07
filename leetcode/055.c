#include <stdbool.h>
#include <stdio.h>

bool canJump(int* nums, int numsSize) {
    if(numsSize == 0 || numsSize == 1) return true;
    int is_access[numsSize];
    for(int i = 0; i < numsSize; ++i) {
        is_access[i] = 0;
    }    
    is_access[0] = 1;
    for(int i = 1, j = 0; i < numsSize; ++i) {
        for(j = 0; j < i; ++j) {
            if(is_access[j] && j + nums[j] >= i) is_access[i] = 1;
        }
    }
    return is_access[numsSize-1];
}

int main() {
    return 0;
}