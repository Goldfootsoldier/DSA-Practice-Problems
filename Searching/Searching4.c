#include <stdio.h>

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int hex_digit_sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 16;
        x /= 16;
    }
    return sum;
}

int search(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (gcd(i, hex_digit_sum(i)) > 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int L, R;
        scanf("%d %d", &L, &R);
        printf("%d\n", search(L, R));
    }
    return 0;
}