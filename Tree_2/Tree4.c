#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[5005];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSets(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int cmp(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e2->w - e1->w;
}

int printheap(int N) {
    return N;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge* edges = (Edge*)malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    qsort(edges, m, sizeof(Edge), cmp);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    long long max_weight = 0;
    int count = 0;

    for (int i = 0; i < m; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            unionSets(edges[i].u, edges[i].v);
            max_weight += edges[i].w;
            count++;
            if (count == n - 1) break;
        }
    }

    printf("%lld\n", max_weight);
    free(edges);
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