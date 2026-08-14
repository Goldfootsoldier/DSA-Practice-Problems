#include <stdio.h>
void stockBuySell(int price[], int n) {
    if (n == 1) return;
    int i = 0;
    int count = 0;
    while (i < n - 1) {
        while ((i < n - 1) && (price[i + 1] <= price[i])) {
            i++;
        }
        if (i == n - 1) break;
        int buy = i++;
        while ((i < n) && (price[i] >= price[i - 1])) {
            i++;
        }
        int sell = i - 1;
        printf("(%d %d)", buy, sell);
        count++;
    }
    if (count == 0) {
        printf("No Profit");
    }
    printf("\n");
}
int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) break;
        int price[n];
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &price[i]) != 1) break;
        }
        stockBuySell(price, n);
    }
    return 0;
}
