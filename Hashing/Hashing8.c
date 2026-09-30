#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long index;
    int value;
} SetElement;

int main() {
    long long n;
    int q;
    if (scanf("%lld %d", &n, &q) != 2) return 0;

    SetElement* active = (SetElement*)malloc(q * sizeof(SetElement));
    int active_count = 0;

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            long long k;
            scanf("%lld", &k);
            int found = 0;
            for (int j = 0; j < active_count; j++) {
                if (active[j].index == k) {
                    active[j].value = 7;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                active[active_count].index = k;
                active[active_count].value = 7;
                active_count++;
            }
        } else if (type == 2) {
            long long y;
            scanf("%lld", &y);
            long long min_idx = -1;
            for (int j = 0; j < active_count; j++) {
                if (active[j].value == 7 && active[j].index >= y) {
                    if (min_idx == -1 || active[j].index < min_idx) {
                        min_idx = active[j].index;
                    }
                }
            }
            printf("%lld\n", min_idx);
        }
    }

    free(active);
    return 0;
}