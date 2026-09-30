#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int to;
    struct Node* next;
} Node;

Node* adj[200005];
int dp[200005][2];

void link(int i, int j) {
    Node* new1 = (Node*)malloc(sizeof(Node));
    new1->to = j;
    new1->next = adj[i];
    adj[i] = new1;

    Node* new2 = (Node*)malloc(sizeof(Node));
    new2->to = i;
    new2->next = adj[j];
    adj[j] = new2;
}

void dfs(int p, int u) {
    dp[u][0] = 0;
    dp[u][1] = 0;

    int sum_max = 0;
    Node* curr = adj[u];
    while (curr) {
        int v = curr->to;
        if (v != p) {
            dfs(u, v);
            sum_max += (dp[v][0] > dp[v][1] ? dp[v][0] : dp[v][1]);
        }
        curr = curr->next;
    }

    dp[u][0] = sum_max;

    curr = adj[u];
    while (curr) {
        int v = curr->to;
        if (v != p) {
            int current_take = 1 + dp[v][0] + (sum_max - (dp[v][0] > dp[v][1] ? dp[v][0] : dp[v][1]));
            if (current_take > dp[u][1]) {
                dp[u][1] = current_take;
            }
        }
        curr = curr->next;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        link(u, v);
    }

    dfs(0, 1);

    int ans = dp[1][0] > dp[1][1] ? dp[1][0] : dp[1][1];
    printf("%d\n", ans);

    return 0;
}