#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bin_to_dec(int num, int len) {
    int result = 0;
    int pop = 0;
    int mod = 0;
    while(len--) {
        mod = pow(10, len);
        pop = num / mod;
        num %= mod;
        result += pop * pow(2, len);
    }
    return result;
}

char* addBinary(char* a, char* b) {
    int tmp_a = 0;
    int tmp_b = 0;
    sscanf(a, "%d", &tmp_a);
    sscanf(b, "%d", &tmp_b);
    int len_a = sizeof(a) / sizeof(char);
    int len_b = sizeof(b) / sizeof(char);
    int ia = bin_to_dec(tmp_a, len_a);
    int ib = bin_to_dec(tmp_b, len_b);
    int sum = ia + ib;
    char* char_sum;
    // sprintf(char_sum, "%d", sum);
    itoa(sum,char_sum,2);
    return char_sum;
}



int main() {
    char* a = "1010";
    char* b = "1011";
    printf("%s\n", addBinary(a, b));
}
