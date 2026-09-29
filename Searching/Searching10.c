#include <stdio.h>
#include <math.h>

long long get_count(long long val) {
    if (val < 1) return 0;
    long long sum = 0;
    for (long long i = 1; i <= val; i++) {
        long long fl = (long long)sqrt(i);
        long long cl = (i + 1) / 2;
        sum += i * fl + cl;
    }
    return sum;
}

long long get_element_index(long long pos) {
    long long low = 1, high = 1000000, ans = 1;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (get_count(mid) >= pos) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int Q;
    if (scanf("%d", &Q) != 1) return 0;
    while (Q--) {
        long long L, R;
        scanf("%lld %lld", &L, &R);
        long long ans1 = get_element_index(L);
        long long ans2 = get_element_index(R);
        long long l = L;
        while (l < ans1) {
            l++;
        }
        printf("%lld\n", ans2 - ans1 + 1);
    }
    return 0;
}