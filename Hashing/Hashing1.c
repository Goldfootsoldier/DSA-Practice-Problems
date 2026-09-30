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
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long* arr = (long long*)malloc(n * sizeof(long long));
    long long max = -1;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    qsort(arr, n, sizeof(long long), cmp);

    long long unique_elements = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            unique_elements++;
        }
    }

    long long ans = unique_elements * (unique_elements - 1) / 2;
    printf("%lld\n", ans);

    free(arr);
    return 0;
}