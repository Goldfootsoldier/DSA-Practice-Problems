#include <stdio.h>

int tree[800005];

int min(int a, int b) {
    return a < b ? a : b;
}

void build(int *aa, int k, int l, int r) {
    if (l == r) {
        tree[k] = aa[l];
        return;
    }
    int mid = (l + r) / 2;
    build(aa, 2 * k, l, mid);
    build(aa, 2 * k + 1, mid + 1, r);
    tree[k] = min(tree[2 * k], tree[2 * k + 1]);
}

int query(int k, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[k];
    }
    if (r < ql || l > qr) {
        return 2000000000;
    }
    int mid = (l + r) / 2;
    return min(query(2 * k, l, mid, ql, qr), query(2 * k + 1, mid + 1, r, ql, qr));
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;
    int a[200005];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(a, 1, 1, n);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(1, 1, n, l, r));
    }
    return 0;
}