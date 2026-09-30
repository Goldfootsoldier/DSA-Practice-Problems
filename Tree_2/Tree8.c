#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    int count;
} Ghost;

int main() {
    int n;
    long long m;
    if (scanf("%d %lld", &n, &m) != 2) return 0;

    int *titles = (int*)calloc(100005, sizeof(int));
    int best_age = 0;
    int max_titles = 0;

    for (int i = 0; i < n; i++) {
        int age;
        scanf("%d", &age);

        titles[age]++;

        if (titles[age] > max_titles) {
            max_titles = titles[age];
            best_age = age;
        } else if (titles[age] == max_titles) {
            if (age > best_age) {
                best_age = age;
            }
        }

        printf("%d %d\n", best_age, max_titles);
    }

    free(titles);
    return 0;
}