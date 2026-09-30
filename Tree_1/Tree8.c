#include <stdio.h>
#include <stdlib.h>

int tree[800005];

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(2 * node, l, mid, idx, val);
    else update(2 * node + 1, mid + 1, r, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[node];
    if (r < ql || l > qr) return 0;
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;
    int p[200005];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int p_val[200005];
    for (int i = 1; i <= n; i++) p_val[i] = p[i];

    for (int i = 1; i <= n; i++) {
        update(1, 1, 100000, p[i], 1);
    }

    while (q--) {
        char type[2];
        scanf("%s", type);
        if (type[0] == '!') {
            int k, x;
            scanf("%d %d", &k, &x);
            update(1, 1, 100000, p_val[k], -1);
            p_val[k] = x;
            update(1, 1, 100000, p_val[k], 1);
        } else {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", query(1, 1, 100000, a, b));
        }
    }
    return 0;
}