#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode List;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(ListNode));
    struct ListNode* list_node = head;
    while(l1 && l2) {
        if(l1->val <= l2->val) {
            list_node->next = l1;
            list_node = list_node->next;
            l1 = l1->next;
        } else {
            list_node->next = l2;
            list_node = list_node->next;
            l2 = l2->next;           
        }
    }
    if(!l1) {
        list_node->next = l2;
    } else {
        list_node->next = l1;
    }
    head = head->next;
    return head;
}