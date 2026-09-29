#include <stdio.h>

int queue[100005];
int front = 0, rear = 0;

void enqueue(int val) {
    queue[rear++] = val;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int biggest = -1, big = -1, medium = -1;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        enqueue(a);

        if (a > biggest) {
            medium = big;
            big = biggest;
            biggest = a;
        } else if (a > big) {
            medium = big;
            big = a;
        } else if (a > medium) {
            medium = a;
        }

        if (i < 2) {
            printf("-1\n");
        } else {
            long long ans = (long long)biggest * big * medium;
            printf("%lld\n", ans);
        }
    }

    return 0;
}