/*
 * @author: Gallifrey Zhang
 * @date: 2018/07/30
 * 
 * The solution to the Linear Diophantine Equation
 * need use: greatest common divisor (euclidean algorithm and its extension).
 */

#include <stdio.h>
#include <stdlib.h>
#include "diophante.h"

/*
 * Initial the first two nodes for a and b. 
 */
list* init(int a, int b){
    list* head = (list*)malloc(sizeof(list));
    list* node = (list*)malloc(sizeof(list));
    head->r = a;
    head->q = -1;
    head->s = 1;
    head->t = 0;
    head->next = node;
    head->prior = NULL;
    node->r = b;
    node->s = 0;
    node->t = 1;
    node->next = NULL;
    node->prior = head;
    return head;
}

list* igcdex(list* cnode){
    int r = 0;
    list* new_node = NULL;
    cnode->q = cnode->prior->r / cnode->r;
    r = cnode->prior->r % cnode->r;
    while(r){
        new_node = (list*)malloc(sizeof(list));
        new_node->r = r;
        cnode->next = new_node;
        new_node->prior = cnode;
        new_node->next = NULL;
        cnode = new_node;
        cnode->q = cnode->prior->r / cnode->r;
        r = cnode->prior->r % cnode->r;
    }
    return cnode;
}

/* 
 * Figure out the Bezout Coefficient
 */
void trace(list* cnode){
    list* above_first = NULL;
    list* above_second = NULL;
    while(cnode){
        above_first = cnode->prior;
        above_second = above_first->prior;
        cnode->s = above_second->s - above_first->q * above_first->s;
        cnode->t = above_second->t - above_first->q * above_first->t;
        cnode = cnode->next;
    }
    above_first = NULL;
    above_second = NULL;
}

void delete_list(list* head){
    list* npointer = head->next;
    free(head);
    head = NULL;
    list* cpointer = NULL;
    while(npointer){
        cpointer = npointer;
        npointer = npointer->next;
        free(cpointer);
        cpointer = NULL;
    }
}

/*
 * a*x + b*y = c
 * d = gcd(a, b) and a*s + b*t = d
 * d|c and q = c/d 
 * x = s*q, y = t*q
 */
void diop_linear(int a, int b, int c){
    list* head = init(a, b);
    list* tail = igcdex(head->next);
    trace(head->next->next);
    printf("gcd(%d, %d) = %d = %d*%d + %d*%d\n\n",
            head->r, head->next->r, tail->r, tail->s, head->r, tail->t, head->next->r
        );
    printf("ax + by = c,  (a, b, c) = (%d, %d, %d)\n\n", a, b, c);
    int q = c / tail->r;
    if(q * tail->r == c){
        printf("(x0, y0) = (%d, %d)\n", q * tail->s, q * tail->t);
        printf("(x, y) = (x0, y0) + (%d, %d) * n\n\n", b / tail->r, -a / tail->r);
    }else printf("no solution!\n\n");
    delete_list(head);
    free(head);
    head = NULL;
    tail = NULL;
}
