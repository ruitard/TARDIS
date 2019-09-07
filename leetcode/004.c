#include <stdio.h>

int bound(int* a, int low, int high, int* b, unsigned int k) {
    int mid = low + (high-low)/2;
    int j;
    while (low < high) {
        mid = low + (high-low)/2;
        j = k - mid - 1;
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int low = 0;
    int high = nums1Size;
    if ((nums1Size%2) ^ (nums2Size%2)) {

    } else {

    }

    int len = nums1Size + nums2Size;
    int mid, i = 0, j = 0, count = 0;
    double res;
    if (len % 2) {
        mid = len/2 + 1;
        while (count < mid) {
            
        }
    } else {
        mid = len / 2;
    }
}