

bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }
    int real = x;
    int pop = x % 10;
    x /= 10;
    int rev = pop;
    while(x) {
        pop = x % 10;
        x /= 10;
        rev = rev * 10 + pop;
    }
    if(real == rev) return true;
    return false;
}