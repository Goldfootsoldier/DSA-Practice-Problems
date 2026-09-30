#include <stdio.h>
#include <stdlib.h>

int parent[100005];
int sz[100005];
int components;
int max_size;

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

int join(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        if (sz[root_i] < sz[root_j]) {
            int temp = root_i;
            root_i = root_j;
            root_j = temp;
        }
        parent[root_j] = root_i;
        sz[root_i] += sz[root_j];
        if (sz[root_i] > max_size) {
            max_size = sz[root_i];
        }
        components--;
        return 1;
    }
    return 0;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    components = n;
    max_size = 1;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        join(u, v);
        printf("%d %d\n", components, max_size);
    }

    return 0;
}