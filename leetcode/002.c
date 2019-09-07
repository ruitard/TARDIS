#include <stdlib.h>
#include <stdio.h>
 
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node = head;
    while(l1 && l2) {        
        struct ListNode* tmp_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp_node->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        tmp_node->next = NULL;
        node->next = tmp_node;
        node = tmp_node;
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1 == NULL && l2 == NULL && carry) {
        struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->next = NULL;
        new_node->val = 1;
        node->next = new_node;
        return head->next;
    }
    if(l1 != NULL) {
        node->next = l1;
        while(l1) {
            int tmp = carry;
            carry = (l1->val + carry) / 10;
            l1->val = (l1->val + tmp) % 10;

            if(l1->next == NULL && carry == 1) {
                struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
                new_node->next = NULL;
                new_node->val = 1;
                l1->next = new_node;
                break;
            }
            l1 = l1->next;
        }
    } else {
        node->next = l2;
        while(l2) {
            int tmp = carry;
            carry = (l2->val + carry) / 10;
            l2->val = (l2->val + tmp) % 10;
            if(l2->next == NULL && carry == 1) {
                struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
                new_node->next = NULL;
                new_node->val = 1;
                l2->next = new_node;
                break;
            }
            l2 = l2->next;
        }
    }    
    return head->next;
}

int main() {
    printf("hello world\n");
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