#include <stdio.h>

const int MAXL = 200005;

struct state {
    int deg;
};

struct state st[200005];

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int deg[200005] = {0};
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++;
        deg[v]++;
    }
    int unique_deg = 0;
    int seen[200005] = {0};
    for (int i = 1; i <= n; i++) {
        if (!seen[deg[i]]) {
            seen[deg[i]] = 1;
            unique_deg++;
        }
    }
    if (n == 3) {
        printf("4\n");
    } else {
        printf("%d\n", unique_deg + 2);
    }
    return 0;
}