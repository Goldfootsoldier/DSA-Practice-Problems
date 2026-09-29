#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    long long a[3005];
    int f[3005];
    int g[3005];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[i] = -1;
        g[i] = -1;
    }

    int st1[3005];
    int top1 = -1;
    for (int i = 0; i < n; i++) {
        while (top1 != -1 && a[st1[top1]] < a[i]) {
            f[st1[top1--]] = i;
        }
        st1[++top1] = i;
    }

    int st2[3005];
    int top2 = -1;
    for (int i = 0; i < n; i++) {
        while (top2 != -1 && a[st2[top2]] > a[i]) {
            g[st2[top2--]] = i;
        }
        st2[++top2] = i;
    }

    for (int i = 0; i < n; i++) {
        if (f[i] != -1 && g[f[i]] != -1) {
            printf("%lld ", a[g[f[i]]]);
        } else {
            printf("-1 ");
        }
    }
    printf("\n");
    return 0;
}