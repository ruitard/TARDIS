#include <stdio.h>

void exchange(int* a, int i, int j) {
/*  a[i] = a[i] ^ a[j];
    a[j] = a[j] ^ a[i];
    a[i] = a[i] ^ a[j]; 
*/
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

// []
int partition(int* a, int p, int r) {
    int x = a[r];
    int i = p - 1;
    for(int j = p; j < r; ++j) {
        if(a[j] <= x) {
            i = i + 1;
            exchange(a, i, j);
        }
    }
    exchange(a, i+1, r);
    return i + 1;
}

// []
void quick_sort(int* a, int p, int r) {
    if(p < r) {
        int q = partition(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }
}

void sort(int* a, int len) {
    quick_sort(a, 0, len-1);
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    sort(people, peopleSize);
    int ans = 0;
    int i = 0;
    int j = peopleSize - 1;
    while(i <= j) {
        ans += 1;
        if(people[i] + people[j] <= limit) {
            ++i;
        }
        --j;
    }
}

int main() {
    int a[] = {4,1,1,3,2,5,2};
    int len = 7;
    int* ap = a;
    // sort(ap, len);
    exchange(ap, 1, 1);
    for(int i = 0; i < len; ++i) {
        printf("%d ", ap[i]);
    }printf("\n");
    return 0;
}