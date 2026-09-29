#include <stdio.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int t = 0; t < T; t++) {
        int n;
        long long d;
        scanf("%d %lld", &n, &d);
        long long x[1005];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &x[i]);
        }
        long long current_day = d;
        for (int i = n - 1; i >= 0; i--) {
            current_day = (current_day / x[i]) * x[i];
        }
        printf("%lld\n", current_day);
    }
    return 0;
}