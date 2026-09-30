#include <stdio.h>
#include <stdlib.h>

int hash[200005];

int main() {
    int M, Q, N;
    if (scanf("%d %d %d", &M, &Q, &N) != 3) return 0;

    int* A = (int*)malloc(N * sizeof(int));
    int range = Q * M;

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        int val = A[i];
        hash[val]++;
    }

    int max_rating = 0;

    for (int i = 0; i < N; i++) {
        int current_rating = 0;
        int target = A[i];
        for (int j = 0; j < N; j++) {
            if (abs(A[j] - target) <= range && (abs(A[j] - target) % M == 0)) {
                current_rating++;
            }
        }
        if (current_rating > max_rating) {
            max_rating = current_rating;
        }
    }

    printf("%d\n", max_rating);

    free(A);
    return 0;
}