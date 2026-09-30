#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int to;
    struct Node* next;
} Node;

Node* adj[100005];
int visited[100005];

void add_edge(int u, int v) {
    Node* new1 = (Node*)malloc(sizeof(Node));
    new1->to = v;
    new1->next = adj[u];
    adj[u] = new1;

    Node* new2 = (Node*)malloc(sizeof(Node));
    new2->to = u;
    new2->next = adj[v];
    adj[v] = new2;
}

void dfs(int u) {
    visited[u] = 1;
    Node* curr = adj[u];
    while (curr) {
        if (!visited[curr->to]) {
            dfs(curr->to);
        }
        curr = curr->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int orig_m = m;
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    int components[100005];
    int k = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components[k++] = i;
            dfs(i);
        }
    }

    printf("%d\n", k - 1);
    for (int i = 0; i < k - 1; i++) {
        printf("%d %d\n", components[i], components[i + 1]);
    }

    return 0;
}