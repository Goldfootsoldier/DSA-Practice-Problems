#include <stdio.h>
#include <stdlib.h>

long long c[105];
int u_edge[100005], v_edge[100005];
long long mask_edge[100005];

int parent[100005];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

int unionSets(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
        return 1;
    }
    return 0;
}

int main() {
    int n, m, k;
    if (scanf("%d %d %d", &n, &m, &k) != 3) return 0;

    for (int i = 1; i <= k; i++) {
        scanf("%lld", &c[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v, l;
        scanf("%d %d %d", &u, &v, &l);
        u_edge[i] = u;
        v_edge[i] = v;
        long long msk = 0;
        for (int j = 0; j < l; j++) {
            int token_idx;
            scanf("%d", &token_idx);
            msk |= (1LL << (token_idx - 1));
        }
        mask_edge[i] = msk;
    }

    long long best_cost = -1;

    for (long long mask = 0; mask < (1LL << k); mask++) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        int components = n;
        for (int i = 0; i < m; i++) {
            if ((mask_edge[i] & mask) == mask_edge[i]) {
                if (unionSets(u_edge[i], v_edge[i])) {
                    components--;
                }
            }
        }

        if (components == 1) {
            long long current_cost = 0;
            for (int i = 0; i < k; i++) {
                if ((mask >> i) & 1) {
                    current_cost += c[i + 1];
                }
            }
            if (best_cost == -1 || current_cost < best_cost) {
                best_cost = current_cost;
            }
        }
    }

    printf("%lld\n", best_cost);
    return 0;
}