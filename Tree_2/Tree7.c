#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int S[200005];
    int size = N;
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }

    int Q;
    if (scanf("%d", &Q) != 1) return 0;

    while (Q--) {
        int val;
        scanf("%d", &val);

        int exists = 0;
        for (int i = 0; i < size; i++) {
            if (S[i] == val) {
                exists++;
            }
        }

        if (exists < 2) {
            S[size++] = val;
        }
        printf("%d\n", size);
    }

    for (int i = 0; i < size; i++) {
        printf("%d%c", S[i], (i == size - 1) ? '\n' : ' ');
    }

    return 0;
}