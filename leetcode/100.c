#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct QueueNode {
    TreeNode* tree_node;
    struct QueueNode* next;
}QueueNode; 

typedef struct {
    QueueNode* front;
    QueueNode* real; 
}Queue;

bool is_queue_empty(Queue queue) {
    if(queue.real->next == queue.front) {
        return true;
    } else {
        return false;
    }
}

void push_queue(Queue queue, TreeNode* tree_node) {
    QueueNode* new_queue_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_queue_node->tree_node = tree_node;
    new_queue_node->next = NULL;
    queue.real->next = new_queue_node;
    queue.real->next = queue.real;
}

void push_queue(Queue queue, QueueNode* queue_node) {
    queue.real->next = queue_node;
    queue.real = queue.real->next;
}

QueueNode* get_queue_front(Queue queue) {
    return queue.front;
}

bool pop_queue(Queue queue) {
    if(is_queue_empty(queue)) return false;
    QueueNode* pop_node = queue.front;
    queue.front = queue.front->next;
    free(pop_node);
    return true;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    return true;
}

int main() {
    char str[100];
    char* s1 = "Hello ";
    char* s2 = "World!";
    strcat(str, 1);
    strcat(str, s2);
    printf("%s\n", str);
    return 0;
}
