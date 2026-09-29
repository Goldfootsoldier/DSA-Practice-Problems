#include <stdio.h>

struct twoStacks {
    int arr[5];
    int top1;
    int top2;
    int size;
};

void push1(struct twoStacks* ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->top1++;
        ts->arr[ts->top1] = x;
    }
}

void push2(struct twoStacks* ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->top2--;
        ts->arr[ts->top2] = x;
    }
}

int pop1(struct twoStacks* ts) {
    if (ts->top1 >= 0) {
        int x = ts->arr[ts->top1];
        ts->top1--;
        return x;
    }
    return -1;
}

int pop2(struct twoStacks* ts) {
    if (ts->top2 < ts->size) {
        int x = ts->arr[ts->top2];
        ts->top2++;
        return x;
    }
    return -1;
}

int main() {
    struct twoStacks ts;
    ts.size = 5;
    ts.top1 = -1;
    ts.top2 = 5;
    int val;
    for (int i = 1; i <= 5; i++) {
        if (scanf("%d", &val) == 1) {
            if (i % 2 != 0) {
                push1(&ts, val);
            } else {
                push2(&ts, val);
            }
        }
    }
    printf("Popped element from stack1 is:%d\n", pop1(&ts));
    printf("Popped element from stack2 is:%d\n", pop2(&ts));
    printf("Popped element from stack1 is:%d\n", pop1(&ts));
    printf("Popped element from stack2 is:%d\n", pop2(&ts));
    return 0;
}