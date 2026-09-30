#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[15];
    long long spendings[1000];
    int count;
} Festival;

int cmp_desc(const void* a, const void* b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    Festival fest[100];
    int fest_count = 0;

    for (int i = 0; i < n; i++) {
        char s[15];
        long long x;
        scanf("%s %lld", s, &x);

        int found = -1;
        for (int j = 0; j < fest_count; j++) {
            if (strcmp(fest[j].name, s) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(fest[fest_count].name, s);
            fest[fest_count].spendings[0] = x;
            fest[fest_count].count = 1;
            fest_count++;
        } else {
            fest[found].spendings[fest[found].count++] = x;
        }
    }

    char best_name[15] = "";
    long long max_sum = -1;

    for (int i = 0; i < fest_count; i++) {
        qsort(fest[i].spendings, fest[i].count, sizeof(long long), cmp_desc);
        long long sum = 0;
        int limit = fest[i].count < 3 ? fest[i].count : 3;
        for (int k = 0; k < limit; k++) {
            sum += fest[i].spendings[k];
        }

        if (sum > max_sum) {
            max_sum = sum;
            strcpy(best_name, fest[i].name);
        } else if (sum == max_sum) {
            if (strcmp(fest[i].name, best_name) < 0) {
                strcpy(best_name, fest[i].name);
            }
        }
    }

    printf("%s %lld\n", best_name, max_sum);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}