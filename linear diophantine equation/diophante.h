/*
 * @author: Gallifrey Zhang
 * @date: 2018/07/30
 * 
 * Linear Diophantine Equation: a*x + b*y = c
 * You can solve it by using diop_linear(a, b, c) if there is a solution.
 */

// doubly linked list
typedef struct node{
    int r;  // remainder
    int q;  // quotient
    int s;  // Bezout Coefficient to a 
    int t;  // Bezout Coefficient to b 
    struct node* next;
    struct node* prior;   
}list;

void diop_linear(int, int, int);
