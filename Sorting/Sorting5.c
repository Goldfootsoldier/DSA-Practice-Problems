#include <stdio.h>

typedef long long ll;

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        ll n, L;
        scanf("%lld %lld", &n, &L);
        ll l[2005], r[2005];
        for (ll i = 0; i < n; i++) {
            scanf("%lld %lld", &l[i], &r[i]);
        }

        int possible = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                ll start = l[i];
                ll end = start + L;
                
                if (r[j] == end) {
                    ll cur_right = start;
                    while (cur_right < end) {
                        ll max_right = cur_right;
                        for (ll k = 0; k < n; k++) {
                            if (l[k] <= cur_right && r[k] > max_right) {
                                max_right = r[k];
                            }
                        }
                        if (cur_right == max_right) {
                            break;
                        }
                        cur_right = max_right;
                    }
                    if (cur_right >= end) {
                        possible = 1;
                        break;
                    }
                }
            }
            if (possible) break;
        }

        if (possible) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}