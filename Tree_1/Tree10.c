#include <stdio.h>

int tree[800005];
int x[200005];

void build(int k, int l, int r) {
    if (l == r) {
        tree[k] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    tree[k] = tree[2 * k] + tree[2 * k + 1];
}

int query_and_update(int k, int l, int r, int p) {
    tree[k]--;
    if (l == r) {
        return l;
    }
    int mid = (l + r) / 2;
    if (tree[2 * k] >= p) {
        return query_and_update(2 * k, l, mid, p);
    } else {
        return query_and_update(2 * k + 1, mid + 1, r, p - tree[2 * k]);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    build(1, 1, n);
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        int idx = query_and_update(1, 1, n, p);
        printf("%d ", x[idx]);
    }
    printf("\n");
    return 0;
}