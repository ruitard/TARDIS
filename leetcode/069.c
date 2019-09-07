#include <stdio.h>
#include <limits.h>

int mySqrt(int x) {
    if(x == 0) return 0;
    int i = 0;
    int j = x;
    int m = (i + j) / 2;
    for(int k = 0; k < 150; ++k) {
        printf("i = %d\n", i);
        printf("j = %d\n", j);
        printf("m = %d\n", m);

        if(m*m == x) return m;
        else if(m*m > x) {
            j = m - 1;
            m = (i + j) / 2;
        } else {
            i = m + 1;
            m = (i + j) / 2;
        }
    }
    return m*m > x ? m-1 : m;
}

int main() {
    // printf("%d\n", mySqrt(5));
    // printf("%d\n", mySqrt(2147395599));
    // printf("%d\n", mySqrt(8));
    printf("%d\n", INT_MAX);
    int n = INT_MAX*INT_MAX;
    printf("%d\n", n);
    return 0;
}