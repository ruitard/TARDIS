#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;
    struct ListNode* slow_ptr = head;
    struct ListNode* quick_ptr = head->next;
    while(quick_ptr) {
        if(quick_ptr == slow_ptr) return true;
        if(quick_ptr->next == NULL) return false;
        quick_ptr = quick_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return false;
}