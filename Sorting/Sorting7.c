#include <stdio.h>

void sort(int a[], int n, int flag) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (flag == 0) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            } else {
                if (a[j] < a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int n;
        scanf("%d", &n);
        int A[55], B[55];
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        for (int i = 0; i < n; i++) scanf("%d", &B[i]);

        sort(A, n, 0);
        sort(B, n, 1);

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)A[i] * B[i];
        }
        printf("%lld\n", sum);
    }
    return 0;
}