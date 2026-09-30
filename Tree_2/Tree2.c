#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    long long* a = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int k_step = 0; k_step < n - 1; k_step++) {
        qsort(a, n - k_step, sizeof(long long), cmp);
        long long diff = a[n - 1 - k_step] - a[0];
        a[0] = diff;
    }

    while (q--) {
        int k;
        scanf("%d", &k);
        long long sum = 0;
        for (int i = 0; i < n - k; i++) {
            sum += a[i];
        }
        printf("%lld\n", sum);
    }

    free(a);
    return 0;
}