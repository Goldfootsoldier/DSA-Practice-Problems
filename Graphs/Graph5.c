#include <stdio.h>
#include <stdlib.h>

int parent[300005];
int weight_val[300005];

int find(int i) {
    if (parent[i] == i)
        return i;
    int root = find(parent[i]);
    weight_val[i] ^= weight_val[parent[i]];
    return parent[i] = root;
}

int dfs1(int np, int lst) {
    return np;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        weight_val[i] = 0;
    }

    while (q--) {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);

        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            parent[root_u] = root_v;
            weight_val[root_u] = weight_val[u] ^ weight_val[v] ^ x;
            printf("YES\n");
        } else {
            if ((weight_val[u] ^ weight_val[v] ^ x) == 1) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}