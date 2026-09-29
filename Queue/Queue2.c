#include <stdio.h>
#include <string.h>

char s[200005];
int tree[800005];
int pref[800005];
int suff[800005];
int len[800005];

int max(int a, int b) {
    return a > b ? a : b;
}

void pull(int k, int l, int r) {
    int mid = (l + r) / 2;
    int left = 2 * k;
    int right = 2 * k + 1;

    pref[k] = pref[left];
    if (pref[left] == len[left] && s[l - 1] == s[mid]) {
        pref[k] += pref[right];
    }

    suff[k] = suff[right];
    if (suff[right] == len[right] && s[mid - 1] == s[r - 1]) {
        suff[k] += suff[left];
    }

    tree[k] = max(tree[left], tree[right]);
    if (s[mid - 1] == s[mid]) {
        tree[k] = max(tree[k], suff[left] + pref[right]);
    }
}

void build(int k, int l, int r) {
    len[k] = r - l + 1;
    if (l == r) {
        tree[k] = 1;
        pref[k] = 1;
        suff[k] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    pull(k, l, r);
}

void update(int k, int l, int r, int idx) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) {
        update(2 * k, l, mid, idx);
    } else {
        update(2 * k + 1, mid + 1, r, idx);
    }
    pull(k, l, r);
}

int main() {
    if (scanf("%s", s) != 1) return 0;
    int n = strlen(s);
    build(1, 1, n);

    int m;
    if (scanf("%d", &m) != 1) return 0;
    while (m--) {
        int x;
        scanf("%d", &x);
        s[x - 1] = (s[x - 1] == '0') ? '1' : '0';
        update(1, 1, n, x);
        printf("%d ", tree[1]);
    }
    printf("\n");
    return 0;
}