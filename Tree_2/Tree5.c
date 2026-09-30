#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void push(MinHeap *hp, int val) {
    if (hp->size == hp->capacity) return;
    hp->data[hp->size] = val;
    int i = hp->size;
    hp->size++;
    while (i != 0 && hp->data[(i - 1) / 2] > hp->data[i]) {
        swap(&hp->data[i], &hp->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int q_pop(MinHeap *hp) {
    if (hp->size <= 0) return -1;
    if (hp->size == 1) {
        hp->size--;
        return hp->data[0];
    }
    int root = hp->data[0];
    hp->data[0] = hp->data[hp->size - 1];
    hp->size--;
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;
        if (right < hp->size && hp->data[right] < hp->data[left]) smallest = right;
        if (hp->data[i] <= hp->data[smallest]) break;
        swap(&hp->data[i], &hp->data[smallest]);
        i = smallest;
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *code = (int*)malloc((n - 2) * sizeof(int));
    int *deg = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) deg[i] = 1;

    for (int i = 0; i < n - 2; i++) {
        scanf("%d", &code[i]);
        deg[code[i]]++;
    }

    MinHeap hp;
    hp.data = (int*)malloc((n + 1) * sizeof(int));
    hp.size = 0;
    hp.capacity = n + 1;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            push(&hp, i);
        }
    }

    for (int i = 0; i < n - 2; i++) {
        int leaf = q_pop(&hp);
        int v = code[i];
        printf("%d %d\n", leaf, v);
        deg[v]--;
        if (deg[v] == 1) {
            push(&hp, v);
        }
    }

    int u = q_pop(&hp);
    int v = q_pop(&hp);
    printf("%d %d\n", u, v);

    free(code);
    free(deg);
    free(hp.data);
    return 0;
}