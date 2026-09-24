#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long long data;
    struct Node *next;
} Node;
typedef struct {
    Node *top;
} Stack;
void initStack(Stack *s) {
    s->top = NULL;
}
void push(Stack *s, long long val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
}
long long peek(Stack *s) {
    return s->top->data;
}
void pop(Stack *s) {
    if (s->top == NULL) return;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
}
int isEmpty(Stack *s) {
    return s->top == NULL;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    long long *a = (long long *)malloc(n * sizeof(long long));
    Stack bStack;
    initStack(&bStack);
    for (int k = 0; k < n; k++) {
        scanf("%lld", &a[k]);
        push(&bStack, a[k]);
    }
    int i = 0;
    int first = 1;
    while (i < n && !isEmpty(&bStack)) {
        long long b_val = peek(&bStack);
        if (!first) {
            printf(" ");
        }
        first = 0;
        if (a[i] > b_val) {
            printf("1");
            pop(&bStack); 
        } else if (a[i] < b_val) {
            printf("2");
            i++;
        } else {
            printf("0");
            i++;
            pop(&bStack);
        }
    }
    printf("\n");
    while (!isEmpty(&bStack)) {
        pop(&bStack);
    }
    free(a);

    return 0;
}