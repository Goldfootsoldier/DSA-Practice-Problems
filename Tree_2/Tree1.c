#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int to;
    struct Node* next;
} Node;

void addEdge(Node** head, int u, int v) {
    Node* new1 = (Node*)malloc(sizeof(Node));
    new1->to = v;
    new1->next = head[u];
    head[u] = new1;

    Node* new2 = (Node*)malloc(sizeof(Node));
    new2->to = u;
    new2->next = head[v];
    head[v] = new2;
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int getCanonicalRepresentation(int u, int p, Node** adj, int* res) {
    int children[1000];
    int count = 0;
    Node* curr = adj[u];
    while (curr) {
        if (curr->to != p) {
            children[count++] = getCanonicalRepresentation(curr->to, u, adj, res);
        }
        curr = curr->next;
    }
    qsort(children, count, sizeof(int), cmp);
    int hash = 17;
    for (int i = 0; i < count; i++) {
        hash = hash * 31 + children[i];
    }
    res[u] = hash;
    return hash;
}

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;

    Node** adj1 = (Node**)calloc(n + 1, sizeof(Node*));
    Node** adj2 = (Node**)calloc(n + 1, sizeof(Node*));

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj1, u, v);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj2, u, v);
    }

    int* res1 = (int*)calloc(n + 1, sizeof(int));
    int* res2 = (int*)calloc(n + 1, sizeof(int));

    int h1 = getCanonicalRepresentation(1, 0, adj1, res1);
    int h2 = getCanonicalRepresentation(1, 0, adj2, res2);

    if (h1 == h2) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    free(res1);
    free(res2);
    free(adj1);
    free(adj2);
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