#include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int a[1005];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        sort(a, n);

        int petrol = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > k) {
                petrol += (a[i] - k);
            }
        }

        if (petrol == 0) {
            printf("-1\n");
        } else {
            printf("%d\n", petrol);
        }
    }
    return 0;
}