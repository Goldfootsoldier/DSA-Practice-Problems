#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char s[100005];
int count_map[100005][26];

void dfs(int u, int p, Node** adj) {
    count_map[u][s[u - 1] - 'a']++;
    Node* curr = adj[u];
    while (curr) {
        if (curr->to != p) {
            dfs(curr->to, u, adj);
            for (int i = 0; i < 26; i++) {
                count_map[u][i] += count_map[curr->to][i];
            }
        }
        curr = curr->next;
    }
}

int main() {
    int N, Q;
    if (scanf("%d %d", &N, &Q) != 2) return 0;

    scanf("%s", s);

    Node** adj = (Node**)calloc(N + 1, sizeof(Node*));

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    dfs(1, 0, adj);

    while (Q--) {
        int u;
        char c;
        scanf("%d %c", &u, &c);
        printf("%d\n", count_map[u][c - 'a']);
    }

    return 0;
}