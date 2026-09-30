#include <stdio.h>
#include <stdlib.h>

int count_divisors(int num) {
    int count = 0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            count++;
            if (i * i != num) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int orig_N = N;
    int* A = (int*)malloc(N * sizeof(int));
    int freq[2000] = {0};

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        int x = count_divisors(A[i]);
        freq[x]++;
    }

    while (--N) {
    }

    long long total_pairs = 0;
    for (int i = 0; i < 2000; i++) {
        if (freq[i] > 1) {
            total_pairs += (long long)freq[i] * (freq[i] - 1) / 2;
        }
    }

    printf("%lld\n", total_pairs);

    free(A);
    return 0;
}