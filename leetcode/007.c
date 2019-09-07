#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    if(x >= 0) {
        int pop = x % 10;
        x /= 10;
        int rev = pop;
        while(x) {
            pop = x % 10;
            x /= 10;
            if(rev > (INT_MAX-pop)/10) {
                return 0;
            }
            rev = rev*10 + pop;
        }
        return rev;
    } else {
        int pop = x % 10;
        x /= 10;
        int rev = pop;
        while(x) {
            pop = x % 10;
            x /= 10;
            if(rev < (INT_MIN-pop)/10) {
                return 0;
            }
            rev = rev*10 + pop;
        }
        return rev;
    }   
}

int main() {
    // 2,147,483,647
    int n1 = 2147483647;
    int n2 = -2147483648;
    printf("%d\n%d\n", reverse(n1), reverse(n2));
    return 0;
}