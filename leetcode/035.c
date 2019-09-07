
// int searchInsert(int* nums, int numsSize, int target) {
//     int i = 0;
//     for(i = 0; i < numsSize; ++i) {
//         if(target <= nums[i]) {
//             return i;
//         }
//     }
//     return i;
// }

int search_position(int* nums, int target, int i, int j) {
    if(i >= j) return j;
    int m = (i + j) / 2;
    if(target == nums[m]) return m;
    if(target < nums[m]) return search_position(nums, target, i, m-1);
    if(target > nums[m]) return search_position(nums, target, m+1, j);
}

int searchInsert(int* nums, int numsSize, int target) {
    if(target <= nums[0]) return 0;
    if(target >= nums[numsSize-1]) return numsSize;
    return search_position(nums, target, 0, numsSize-1);
}