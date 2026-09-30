#include <stdio.h>
#include <stdlib.h>

long long tree[800005];
long long lazy_a[800005];
long long lazy_d[800005];
long long arr[200005];

void build(int k, int l, int r) {
    lazy_a[k] = 0;
    lazy_d[k] = 0;
    if (l == r) {
        tree[k] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    tree[k] = tree[2 * k] + tree[2 * k + 1];
}

void push(int k, int l, int r) {
    if (lazy_a[k] == 0 && lazy_d[k] == 0) return;
    int mid = (l + r) / 2;
    long long len_left = mid - l + 1;

    lazy_a[2 * k] += lazy_a[k];
    lazy_d[2 * k] += lazy_d[k];

    lazy_a[2 * k + 1] += lazy_a[k] + lazy_d[k] * len_left;
    lazy_d[2 * k + 1] += lazy_d[k];

    long long n_l = mid - l + 1;
    tree[2 * k] += n_l * lazy_a[k] + n_l * (n_l - 1) / 2 * lazy_d[k];

    long long n_r = r - mid;
    long long a_r = lazy_a[k] + lazy_d[k] * len_left;
    tree[2 * k + 1] += n_r * a_r + n_r * (n_r - 1) / 2 * lazy_d[k];

    lazy_a[k] = 0;
    lazy_d[k] = 0;
}

void update(int k, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        long long start_val = (l - ql + 1);
        lazy_a[k] += start_val;
        lazy_d[k] += 1;
        long long n = r - l + 1;
        tree[k] += n * start_val + n * (n - 1) / 2 * 1;
        return;
    }
    push(k, l, r);
    int mid = (l + r) / 2;
    if (ql <= mid) update(2 * k, l, mid, ql, qr);
    if (qr > mid) update(2 * k + 1, mid + 1, r, ql, qr);
    tree[k] = tree[2 * k] + tree[2 * k + 1];
}

long long query(int k, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[k];
    push(k, l, r);
    int mid = (l + r) / 2;
    long long res = 0;
    if (ql <= mid) res += query(2 * k, l, mid, ql, qr);
    if (qr > mid) res += query(2 * k + 1, mid + 1, r, ql, qr);
    return res;
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
    }

    build(1, 1, n);

    while (q--) {
        int type, a, b;
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1) {
            update(1, 1, n, a, b);
        } else {
            printf("%lld\n", query(1, 1, n, a, b));
        }
    }

    return 0;
}