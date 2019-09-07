#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/* typedef struct StackNode {
    char val;
    struct StackNode* next;
    struct StackNode* prior;
}StackNode;

typedef struct Stack {
    StackNode* peak;
    char peak_val;
}Stack;

bool is_empty(Stack* s) {
    if(s->peak == NULL) return true;
    return false;
}

void push(Stack* stack, char c) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->val = c;
    node->next = NULL;
    if(is_empty(stack)) {       
        node->prior = NULL;
    } else {
        node->prior = stack->peak;
        stack->peak->next = node;
    }
    stack->peak = node;
    stack->peak_val = c;
}

bool pop(Stack* stack) {
    if(is_empty(stack)) return false;
    StackNode* tmp_node = stack->peak;
    stack->peak = tmp_node->prior;
    if(stack->peak == NULL) {
        stack->peak_val = '$';
        return true;
    }
    stack->peak_val = stack->peak->val;
    stack->peak->next = NULL;
    tmp_node->prior = NULL;
    tmp_node->next = NULL;
    free(tmp_node);
    return true;
}

bool match(char c1, char c2) {
    if((c1 == '(') && (c2 == ')')) return true;
    if((c1 == '[') && (c2 == ']')) return true;
    if((c1 == '{') && (c2 == '}')) return true;
    return false;   
}

bool isValid(char* s) {
    if(s == NULL) return false;
    if(s == "") return true;
    size_t len = strlen(s);
    if(len%2 == 1) {
        return false;
    } else {
        Stack* stack = (Stack*)malloc(sizeof(Stack));
        stack->peak = NULL;
        stack->peak_val = '$';
        push(stack, s[0]);
        for(int i = 1; i < len; ++i) {
            // printf("%c %c\n", stack->peak_val, s[i]);
            if(match(stack->peak_val, s[i])) {
                // printf("pop %c\n", s[i]);
                pop(stack);
            } else {
                // printf("push %c\n", s[i]);
                push(stack, s[i]);
            }
        }     
        return is_empty(stack);
    }
} */

struct node {
    char data;
    struct node* next;
};

void init(struct node* head) {
    head = NULL;
}

void push(struct node** head, char data) {
    struct node* tmp = malloc(sizeof(struct node));
    if (tmp == NULL) exit(0);
    tmp->data = data;
    tmp->next = *head;
    *head = tmp;
}

void pop(struct node** head, char* element) {
    struct node* tmp = *head;
    *element = (*head)->data;
    *head = (*head)->next;
    free(tmp);
}

int peak(struct node* head, char* element) {
    if (head) *element = head->data;
    else {
        element = NULL;
        return 0;
    }
    return 1;
}

bool empty(struct node* head) {
    return head==NULL ? true : false;
}

bool is_left_bracket(char brac) {
    if (brac=='(' || brac=='[' || brac=='{') return true;
    else return false;
}

bool is_right_bracket(char brac) {
    if (brac==')' || brac==']' || brac=='}') return true;
    else return false;
}

bool is_bracket_match(char lb, char rb) {
    if (lb=='(' && rb==')') return true;
    if (lb=='[' && rb==']') return true;
    if (lb=='{' && rb=='}') return true;
    return false;
}

bool isValid(char* s) {
    size_t len = strlen(s);
    if (len%2 == 1) return false;
    struct node* stack = NULL;
    init(stack);
    char peak_element;
    for (size_t i = 0; i < len; i++) {
        if (is_left_bracket(s[i])) push(&stack, s[i]);
        else if (is_right_bracket(s[i])) {
            if (peak(stack, &peak_element)) {
                if (is_bracket_match(peak_element, s[i])) pop(&stack, &peak_element);
                else return false;
            } else return false;
        } else return false;
    }
    return empty(stack) ? true : false;
}

int main() {
    // char* s = "";
    printf("%d ", isValid("()"));
    printf("%d ", isValid("()[{})"));
    printf("%d ", isValid("{[]}()"));
    return 0;
}
