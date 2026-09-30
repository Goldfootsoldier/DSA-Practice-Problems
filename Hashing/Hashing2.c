#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve() {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    if (a > b) {
        long long temp = a;
        a = b;
        b = temp;
    }

    double phi = (1.0 + sqrt(5.0)) / 2.0;
    long long k = b - a;
    long long target = (long long)(k * phi);

    if (a == target) {
        printf("sami\n");
    } else {
        printf("canthi\n");
    }
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}