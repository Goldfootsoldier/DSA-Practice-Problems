#include <stdio.h>

int parent1[100005], parent2[100005];

int find1(int i) {
    if (parent1[i] == i) return i;
    return parent1[i] = find1(parent1[i]);
}

int find2(int i) {
    if (parent2[i] == i) return i;
    return parent2[i] = find2(parent2[i]);
}

int main() {
    int n, m1, m2;
    if (scanf("%d %d %d", &n, &m1, &m2) != 3) return 0;

    for (int i = 1; i <= n; i++) {
        parent1[i] = i;
        parent2[i] = i;
    }

    while (m1--) {
        int u, v;
        scanf("%d %d", &u, &v);
        parent1[find1(u)] = find1(v);
    }

    while (m2--) {
        int u, v;
        scanf("%d %d", &u, &v);
        parent2[find2(u)] = find2(v);
    }

    int added_u[100005], added_v[100005];
    int count = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (find1(i) != find1(j) && find2(i) != find2(j)) {
                parent1[find1(i)] = find1(j);
                parent2[find2(i)] = find2(j);
                added_u[count] = i;
                added_v[count] = j;
                count++;
            }
        }
    }

    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", added_u[i], added_v[i]);
    }

    return 0;
}