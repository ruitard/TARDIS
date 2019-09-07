#include <stdlib.h>
#include <stdio.h>
 
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {


}

int main() {
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next = NULL;
    l2->next = NULL;
    l1->val = 5;
    l2->val = 5;
    struct ListNode* r = addTwoNumbers(l1, l2);
    while(r) {
        printf("%d", r->val);
        r = r->next;
    }printf("\n");
    return 0;
}