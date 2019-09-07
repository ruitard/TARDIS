/*
 * @lc app=leetcode id=217 lang=c
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (51.04%)
 * Total Accepted:    309.1K
 * Total Submissions: 605.5K
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an array of integers, find if the array contains any duplicates.
 * 
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node; 

node* create_node(int data) {
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert_node(node *cursor, int data, int* flag) {
    if (cursor == NULL) cursor = create_node(data);
    else {
      if (data < cursor->data) cursor->left = insert_node(cursor->left, data, flag);
      else if (data > cursor->data) cursor->right = insert_node(cursor->right, data, flag);
      else *flag = 1;
    }
    return cursor;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize == 0) return false;
    node* root = NULL;
    int flag = 0;
    root = insert_node(root, nums[numsSize/2], &flag);
    for (int i = numsSize-1; i >= 0; i--) {
        if (i == numsSize/2) continue;
        root = insert_node(root, nums[i], &flag);
        if (flag) return true;
    }
    return false;
}

