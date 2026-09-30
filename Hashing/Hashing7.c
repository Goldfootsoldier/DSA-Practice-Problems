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
    int N;
    if (scanf("%d", &N) != 1) return 0;

    long long* A = (long long*)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    int NA[2000];
    int total_subarrays = N * (N + 1) / 2;
    long long* sums = (long long*)malloc(total_subarrays * sizeof(long long));
    int idx = 0;

    for (int i = 0; i < N; i++) {
        long long current_sum = 0;
        for (int j = i; j < N; j++) {
            current_sum += A[j];
            sums[idx++] = current_sum;
        }
    }

    qsort(sums, total_subarrays, sizeof(long long), cmp);

    long long unique_sum = 0;
    for (int i = 0; i < total_subarrays; i++) {
        if (i == 0 || sums[i] != sums[i - 1]) {
            unique_sum += sums[i];
        }
    }

    printf("%lld\n", unique_sum);

    free(A);
    free(sums);
    return 0;
}