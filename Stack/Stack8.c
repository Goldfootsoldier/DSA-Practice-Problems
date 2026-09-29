#include <stdio.h>

int arr[1000000];
int st[1000000];

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxXor = 0;
    for (int i = 0; i < n; i++) {
        int stack[1000];
        int top = -1;
        stack[++top] = i;

        int currentXor = arr[i];
        st[i] = currentXor;

        for (int j = i + 1; j < n; j++) {
            if (arr[stack[top]] < arr[j]) {
                currentXor = currentXor ^ arr[j];
                st[i] = currentXor;
                stack[++top] = j;
            }
        }
        if (st[i] > maxXor) {
            maxXor = st[i];
        }
    }
    printf("%d\n", maxXor);
    return 0;
}