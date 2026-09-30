#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int to;
    struct Node* next;
} Node;

Node* adj[400005];
Node* adj_rev[400005];
int order[400005], order_size = 0;
int visited[400005];
int comp[400005], num_comp = 0;
int assignment[200005];

void link(int i, int j) {
    Node* new1 = (Node*)malloc(sizeof(Node));
    new1->to = j;
    new1->next = adj[i];
    adj[i] = new1;

    Node* new2 = (Node*)malloc(sizeof(Node));
    new2->to = i;
    new2->next = adj_rev[j];
    adj_rev[j] = new2;
}

void dfs1(int v) {
    visited[v] = 1;
    Node* curr = adj[v];
    while (curr) {
        if (!visited[curr->to]) dfs1(curr->to);
        curr = curr->next;
    }
    order[order_size++] = v;
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    Node* curr = adj_rev[v];
    while (curr) {
        if (comp[curr->to] == -1) dfs2(curr->to, cl);
        curr = curr->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        char s1[10], s2[10];
        scanf("%s %s", s1, s2);
        int x = atoi(s1 + 1);
        int y = atoi(s2 + 1);

        int vx = (s1[0] == '+') ? (2 * x - 1) : (2 * x);
        int vy = (s2[0] == '+') ? (2 * y - 1) : (2 * y);

        int neg_vx = (vx % 2 == 1) ? (vx + 1) : (vx - 1);
        int neg_vy = (vy % 2 == 1) ? (vy + 1) : (vy - 1);

        link(neg_vx, vy);
        link(neg_vy, vx);
    }

    for (int i = 1; i <= 2 * m; i++) {
        if (!visited[i]) dfs1(i);
    }

    for (int i = 1; i <= 2 * m; i++) comp[i] = -1;

    for (int i = 0; i < 2 * m; i++) {
        int v = order[2 * m - 1 - i];
        if (comp[v] == -1) dfs2(v, ++num_comp);
    }

    for (int i = 1; i <= m; i++) {
        if (comp[2 * i - 1] == comp[2 * i]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        assignment[i] = comp[2 * i - 1] > comp[2 * i];
    }

    for (int i = 1; i <= m; i++) {
        printf("%c", assignment[i] ? '+' : '-');
    }
    printf("\n");

    return 0;
}