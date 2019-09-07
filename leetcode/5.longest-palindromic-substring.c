/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.77%)
 * Total Accepted:    497.8K
 * Total Submissions: 1.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
#include <stdio.h>

char* longestPalindrome(char* s) {
    if (s[0] == '\0') return "";
    char ns[2005];
    unsigned int p[2005];
    unsigned int pos = 1;
    ns[0] = '$';
    ns[1] = '#';
    unsigned int i = 0;
    while (s[i] != '\0') {
        ns[2*i+2] = s[i];
        ns[2*i+3] = '#';
        i++;
    }
    unsigned int len = 2*i + 2;
    ns[len] = '\0';
    int id = 1;
    while (id < len) {
        p[id] = 1;
        while ((id-p[id])>0 && (id+p[id])<len && ns[id-p[id]]==ns[id+p[id]]) {
            p[id]++;
        }
        if (p[id] > p[pos]) pos = id; 
        i = id + 1;
        while (i < id + p[id]) {
            if (p[2*id-i] < id+p[id]-i) p[i] = p[2*id-i];
            else if (p[2*id-i] > id+p[id]-i) p[i] = id + p[id] - i;
            else {
                p[i] = p[2*id-i];
                id = i;
                while ((id-p[id])>0 && (id+p[id])<len && ns[id-p[id]]==ns[id+p[id]]) {
                    p[id]++;
                }
                if (p[id] > p[pos]) pos = id; 
                i = id;
            }
            // if (p[i] > p[pos]) pos = i;
            i++;
        }
        id = id + p[id];
        // id++;
    }
    char* res = malloc(sizeof(char)*p[pos]);
    for (i = 0; i <= p[pos]-2; i++) {
        res[i] = ns[2*i+pos-p[pos]+2];
    }
    res[p[pos]-1] = '\0';
    return res;
}

