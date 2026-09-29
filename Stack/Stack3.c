#include <stdio.h>

int getDigitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int N, Q;
    if (scanf("%d %d", &N, &Q) != 2) return 0;
    int arr[100005];
    int digitSum[100005];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        digitSum[i] = getDigitSum(arr[i]);
    }
    for (int q = 0; q < Q; q++) {
        int idx;
        scanf("%d", &idx);
        int ans = -1;
        int stack[100005];
        int top = -1;
        for (int j = N; j > idx; j--) {
            stack[++top] = j;
        }
        while (top != -1) {
            int j = stack[top--];
            if (digitSum[idx] > digitSum[j] && arr[idx] < arr[j]) {
                ans = j;
                break;
            }
        }
        printf("%d ", ans);
    }
    return 0;
}