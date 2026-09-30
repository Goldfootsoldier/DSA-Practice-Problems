#include <stdio.h>

int up[200005][20];

void link(int i, int j) {
    up[i][0] = j;
    for (int k = 1; k < 20; k++) {
        if (up[i][k - 1] != -1) {
            up[i][k] = up[up[i][k - 1]][k - 1];
        } else {
            up[i][k] = -1;
        }
    }
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 20; j++) {
            up[i][j] = -1;
        }
    }

    for (int i = 2; i <= n; i++) {
        int boss;
        scanf("%d", &boss);
        link(i, boss);
    }

    while (q--) {
        int x, k;
        scanf("%d %d", &x, &k);
        for (int j = 0; j < 20; j++) {
            if ((k >> j) & 1) {
                x = up[x][j];
                if (x == -1) break;
            }
        }
        printf("%d\n", x);
    }
    return 0;
}