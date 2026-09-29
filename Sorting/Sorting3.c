#include <stdio.h>

void insertionSort(long int *p, long int n) {
    long int i, key, j;
    for (i = 1; i < n; i++) {
        key = p[i];
        j = i - 1;
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j = j - 1;
        }
        p[j + 1] = key;
    }
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;
    while (q--) {
        int n;
        scanf("%d", &n);
        long int container_sum[105] = {0};
        long int type_sum[105] = {0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long int val;
                scanf("%ld", &val);
                container_sum[i] += val;
                type_sum[j] += val;
            }
        }

        insertionSort(container_sum, n);
        insertionSort(type_sum, n);

        int possible = 1;
        for (int i = 0; i < n; i++) {
            if (container_sum[i] != type_sum[i]) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}