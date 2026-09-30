#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

int main() {
    int m;
    long long n;
    if (scanf("%d %lld", &m, &n) != 2) return 0;

    int *x = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &x[i]);
    }

    for (int i = m / 2 - 1; i >= 0; i--) {
        heapify(x, m, i);
    }

    long long total_gain = 0;

    while (n > 0 && x[0] > 0) {
        total_gain += x[0];
        x[0]--;
        heapify(x, m, 0);
        n--;
    }

    printf("%lld\n", total_gain);

    free(x);
    return 0;
}