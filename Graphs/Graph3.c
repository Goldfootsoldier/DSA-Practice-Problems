#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e9

typedef struct Edge {
    int to;
    int capacity;
    int flow;
    int rev;
    int id;
} Edge;

typedef struct {
    Edge* edges;
    int size;
    int capacity;
} Vector;

Vector adj[1005];
int level[1005];
int ptr[1005];
int parent_edge[1005];

void add_edge(int from, int to, int id) {
    if (adj[from].capacity == adj[from].size) {
        adj[from].capacity = adj[from].capacity == 0 ? 4 : adj[from].capacity * 2;
        adj[from].edges = (Edge*)realloc(adj[from].edges, adj[from].capacity * sizeof(Edge));
    }
    if (adj[to].capacity == adj[to].size) {
        adj[to].capacity = adj[to].capacity == 0 ? 4 : adj[to].capacity * 2;
        adj[to].edges = (Edge*)realloc(adj[to].edges, adj[to].capacity * sizeof(Edge));
    }
    Edge a = {to, 1, 0, adj[to].size, id};
    Edge b = {from, 0, 0, adj[from].size, 0};
    adj[from].edges[adj[from].size++] = a;
    adj[to].edges[adj[to].size++] = b;
}

int bfs(int n, int s, int t) {
    for (int i = 1; i <= n; i++) level[i] = -1;
    level[s] = 0;
    int queue[1005];
    int head = 0, tail = 0;
    queue[tail++] = s;
    while (head < tail) {
        int v = queue[head++];
        for (int i = 0; i < adj[v].size; i++) {
            Edge e = adj[v].edges[i];
            if (e.capacity - e.flow > 0 && level[e.to] == -1) {
                level[e.to] = level[v] + 1;
                queue[tail++] = e.to;
            }
        }
    }
    return level[t] != -1;
}

int dfs(int v, int t, int pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int* cid = &ptr[v]; *cid < adj[v].size; (*cid)++) {
        Edge* e = &adj[v].edges[*cid];
        int tr = e->to;
        if (level[v] + 1 != level[tr] || e->capacity - e->flow == 0) continue;
        int tr_pushed = dfs(tr, t, pushed < (e->capacity - e->flow) ? pushed : (e->capacity - e->flow));
        if (tr_pushed == 0) continue;
        e->flow += tr_pushed;
        adj[tr].edges[e->rev].flow -= tr_pushed;
        return tr_pushed;
    }
    return 0;
}

int dinic(int n, int s, int t) {
    int flow = 0;
    while (bfs(n, s, t)) {
        memset(ptr, 0, sizeof(ptr));
        while (int pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int path[1005];

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v, i);
    }

    int max_flow = dinic(n, 1, n);
    printf("%d\n", max_flow);

    for (int f = 0; f < max_flow; f++) {
        int curr = 1;
        int path_len = 0;
        path[path_len++] = 1;
        while (curr != n) {
            for (int i = 0; i < adj[curr].size; i++) {
                Edge* e = &adj[curr].edges[i];
                if (e->flow > 0) {
                    e->flow = 0;
                    curr = e->to;
                    path[path_len++] = curr;
                    break;
                }
            }
        }
        printf("%d\n", path_len);
        for (int i = 0; i < path_len; i++) {
            printf("%d%c", path[i], (i == path_len - 1) ? '\n' : ' ');
        }
    }

    return 0;
}