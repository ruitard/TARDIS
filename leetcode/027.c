int removeElement(int* nums, int numsSize, int val) {
    int i = -1;
    for(int j = 0; j < numsSize; ++j) {
        if(val != nums[j]) {
            ++i;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}