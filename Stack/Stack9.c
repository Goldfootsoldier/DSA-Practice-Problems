#include <stdio.h>

int q[1000];
int front = 0;
int rear = 0;

void q_push(int val) {
    q[rear++] = val;
}

int q_pop() {
    return q[front++];
}

int q_size() {
    return rear - front;
}

void stack_push(int val) {
    int s = q_size();
    q_push(val);
    for (int i = 0; i < s; i++) {
        q_push(q_pop());
    }
}

int stack_pop() {
    return q_pop();
}

int stack_top() {
    return q[front];
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack_push(val);
    }
    printf("top of element %d\n", stack_top());
    for (int i = 0; i < m; i++) {
        stack_pop();
    }
    printf("top of element %d\n", stack_top());
    return 0;
}