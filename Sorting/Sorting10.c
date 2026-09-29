#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long c;
    long long h;
} Flat;

int compare(const void *a, const void *b) {
    Flat *f1 = (Flat *)a;
    Flat *f2 = (Flat *)b;
    if (f1->c < f2->c) return -1;
    if (f1->c > f2->c) return 1;
    return 0;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t-- > 0) {
        int n;
        scanf("%d", &n);
        Flat flats[2005];
        long long total_h = 0;
        for (int i = 0; i < n; i++) {
            long long x, y, h;
            scanf("%lld %lld %lld", &x, &y, &h);
            flats[i].c = x - y;
            flats[i].h = h;
            total_h += h;
        }

        qsort(flats, n, sizeof(Flat), compare);

        int possible = 0;
        long long left_sum = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            long long group_h = 0;
            while (j < n && flats[j].c == flats[i].c) {
                group_h += flats[j].h;
                j++;
            }

            long long right_sum = total_h - left_sum - group_h;
            if (left_sum == right_sum) {
                possible = 1;
                break;
            }

            left_sum += group_h;
            i = j;
        }

        if (possible) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}