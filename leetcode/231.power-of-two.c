/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (41.69%)
 * Total Accepted:    219.8K
 * Total Submissions: 526.3K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true 
 * Explanation: 2^0 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * Example 3:
 * 
 * 
 * Input: 218
 * Output: false
 * 
 */
// #include <stdio.h>
// typedef int bool;
/**
 * 若n是2此幂，则n的二进制表示的最高位是1，剩余位都是0，
 * n&(n-1)将最低位的1置0，若n是二次幂，则操作之后为0，
 * 否则不为0
 */
bool isPowerOfTwo(int n) {
    return (n>0) && (!(n&(n-1)));
}
