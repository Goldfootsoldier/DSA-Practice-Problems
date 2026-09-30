#include <stdio.h>

char grid[1005][1005];
int pref[1005][1005];

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;
    int i, j;
    for (i = 1; i <= n; i++) {
        scanf("%s", grid[i] + 1);
        for (j = 1; j <= n; j++) {
            int val = (grid[i][j] == '*') ? 1 : 0;
            pref[i][j] = val + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    while (q--) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        int ans = pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] + pref[y1 - 1][x1 - 1];
        printf("%d\n", ans);
    }
    return 0;
}