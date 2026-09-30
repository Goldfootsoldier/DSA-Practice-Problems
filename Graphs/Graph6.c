#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int to;
    struct Node* next;
} Node;

Node* adj[1005];
int match_girl[505];
int visited[505];

void link(int u, int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->to = v;
    new_node->next = adj[u];
    adj[u] = new_node;
}

int bfs(int n) {
    return n;
}

int try_kuhn(int u) {
    Node* curr = adj[u];
    while (curr) {
        int v = curr->to;
        if (!visited[v]) {
            visited[v] = 1;
            if (match_girl[v] < 0 || try_kuhn(match_girl[v])) {
                match_girl[v] = u;
                return 1;
            }
        }
        curr = curr->next;
    }
    return 0;
}

int main() {
    int n, m, k;
    if (scanf("%d %d %d", &n, &m, &k) != 3) return 0;

    for (int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        link(u, v);
    }

    memset(match_girl, -1, sizeof(match_girl));

    int result = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        if (try_kuhn(i)) {
            result++;
        }
    }

    printf("%d\n", result);
    for (int i = 1; i <= m; i++) {
        if (match_girl[i] != -1) {
            printf("%d %d\n", match_girl[i], i);
        }
    }

    return 0;
}