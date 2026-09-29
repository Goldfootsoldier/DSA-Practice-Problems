#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int n, k, p;
        scanf("%d %d %d", &n, &k, &p);

        int sum[55][35];
        memset(sum, 0, sizeof(sum));

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                int val;
                scanf("%d", &val);
                sum[i][j] = sum[i][j - 1] + val;
            }
        }

        int dp[1505];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++) {
            for (int j = p; j >= 0; j--) {
                for (int l = 1; l <= k && l <= j; l++) {
                    dp[j] = max(dp[j], dp[j - l] + sum[i][l]);
                }
            }
        }

        printf("%d\n", dp[p]);
    }
    return 0;
}