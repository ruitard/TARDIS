/*
 * @lc app=leetcode.cn id=62 lang=c
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (51.78%)
 * Total Accepted:    15K
 * Total Submissions: 28.4K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 */

unsigned long long int comb(int m, int n) {
    unsigned long long int c[200][200];
    c[0][0] = 1;
    c[1][0] = 1;
    c[1][1] = 1;
    for (int i = 2, j; i <= m; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (j = 1; j <= n; j++) {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
    return c[m][n];
}

unsigned long long int uniquePaths(int m, int n) {
    // return comb(m+n-2, m-1);
    unsigned long long int c[200];
    for (int i = 0; i < 100; i++) c[i] = 1;
    for (unsigned int i = 2, j; i <= m+n-2; i++) {
        for (j = i-1; j >= 1; j--) {
            c[j] += c[j-1];
        }
    }
    return c[m-1];
}
