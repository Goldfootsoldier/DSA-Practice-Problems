#include <stdio.h>

void calculateSpan(int price[], int n, int S[]) {
    int st[1000];
    int top = -1;

    st[++top] = 0;
    S[0] = 1;

    for (int i = 1; i < n; i++) {
        while (top != -1 && price[st[top]] <= price[i]) {
            top--;
        }
        S[i] = (top == -1) ? (i + 1) : (i - st[top]);
        st[++top] = i;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int price[1000];
    int S[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    calculateSpan(price, n, S);
    printArray(S, n);
    return 0;
}