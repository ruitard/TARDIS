#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* char* multiply(char* num1, char* num2) {
    size_t len1 = strlen(num1);
    size_t len2 = strlen(num2);
} */

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 1;
    while(i) {
        if(nums[i] > nums[i-1]) {
            nums[i] = nums[i] ^ nums[i-1];
            nums[i-1] = nums[i] ^ nums[i-1];
            nums[i] = nums[i] ^ nums[i-1];
            return;
        }
        --i;
    }
    i = 0;
    while(i < numsSize/2) {
        nums[i] = nums[i] ^ nums[numsSize-i-1];
        nums[numsSize-i-1] = nums[i] ^ nums[numsSize-i-1];
        nums[i] = nums[i] ^ nums[numsSize-i-1];
        ++i;
    }
    return;
}

int main() {
    int* nums = (int*)malloc(sizeof(int)*3);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nextPermutation(nums, 3);
    for(int i = 0; i < 3; ++i) {
        printf("%d", nums[i]);
    }
    return 0;
}