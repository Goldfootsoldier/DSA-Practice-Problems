#include <stdio.h>

void sortAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        scanf("%d", &n);
        int g[10005], b[10005];
        for (int i = 0; i < n; i++) scanf("%d", &g[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);
        
        sortAsc(g, n);
        sortDesc(b, n);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (g[i] % b[i] == 0 || b[i] % g[i] == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}