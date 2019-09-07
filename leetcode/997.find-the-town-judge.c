/*
 * @lc app=leetcode id=997 lang=c
 *
 * [997] Find the Town Judge
 *
 * https://leetcode.com/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (48.14%)
 * Total Accepted:    9.1K
 * Total Submissions: 18.9K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * In a town, there are N people labelled from 1 to N.  There is a rumor that
 * one of these people is secretly the town judge.
 * 
 * If the town judge exists, then:
 * 
 * 
 * The town judge trusts nobody.
 * Everybody (except for the town judge) trusts the town judge.
 * There is exactly one person that satisfies properties 1 and 2.
 * 
 * 
 * You are given trust, an array of pairs trust[i] = [a, b] representing that
 * the person labelled a trusts the person labelled b.
 * 
 * If the town judge exists and can be identified, return the label of the town
 * judge.  Otherwise, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 2, trust = [[1,2]]
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 3, trust = [[1,3],[2,3]]
 * Output: 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 3, trust = [[1,3],[2,3],[3,1]]
 * Output: -1
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: N = 3, trust = [[1,2],[2,3]]
 * Output: -1
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
 * Output: 3
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 1000
 * trust.length <= 10000
 * trust[i] are all different
 * trust[i][0] != trust[i][1]
 * 1 <= trust[i][0], trust[i][1] <= N
 * 
 * indegree = N - 1 and outdegree = 0 and unique
 */

#include <stdlib.h>
/*
int findJudge(int N, int** trust, int trustRowSize, int *trustColSizes) {
    int* indegree = calloc(N, sizeof(int));
    int* outdegree = calloc(N, sizeof(int));
    for (int i = 0; i < trustRowSize; i++) {
        outdegree[trust[i][0]-1]++;
        indegree[trust[i][1]-1]++;
    }   
    int mask = -1;
    for (int i = 0; i < N; i++) {
        if (indegree[i]==N-1 && outdegree[i]==0) {
            if (mask == -1) mask = i + 1;
            else return -1;
        }
    }
    free(indegree);
    free(outdegree);
    return mask; 
}
*/


/* 改进版，只使用一个标记数组，空间复杂度减半，并且逻辑判断也变简单了 */
int findJudge(int N, int** trust, int trustRowSize, int *trustColSizes) {
    int* flag = calloc(N, sizeof(int));
    for (int i = 0; i < trustRowSize; i++) {
        flag[trust[i][0]-1] = -1;
        flag[trust[i][1]-1]++;
    }
    for (int i = 0; i < N; i++) {
        if (flag[i] == N-1) return i + 1;
    }
    return -1;
}
