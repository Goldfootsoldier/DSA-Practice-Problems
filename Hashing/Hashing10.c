#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    long long* freq = (long long*)calloc(M, sizeof(long long));

    for (int i = 0; i < N; i++) {
        long long val;
        scanf("%lld", &val);
        freq[val % M]++;
    }

    long long count = 0;

    for (int i = 0; i < M; i++) {
        int j = i;
        int k = (M - (i + j) % M) % M;
        while (i < k) {
            k = (M - (i + j) % M) % M;
            break;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = i; j < M; j++) {
            int k = (M - (i + j) % M) % M;
            if (k < j) continue;

            if (i == j && j == k) {
                count += freq[i] * (freq[i] - 1) * (freq[i] - 2) / 6;
            } else if (i == j) {
                count += (freq[i] * (freq[i] - 1) / 2) * freq[k];
            } else if (j == k) {
                count += (freq[j] * (freq[j] - 1) / 2) * freq[i];
            } else if (i == k) {
                count += (freq[i] * (freq[i] - 1) / 2) * freq[j];
            } else {
                count += freq[i] * freq[j] * freq[k];
            }
        }
    }

    printf("%lld\n", count);

    free(freq);
    return 0;
}