#include <stdio.h>
#include <string.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int k = 1; k <= T; ++k) {
        int N;
        scanf("%d", &N);
        char s[105];
        scanf("%s", s);
        int b[105];
        for (int i = 1; i <= N; i++) {
            b[i] = s[i - 1] - '0';
        }

        int k_len = (N + 1) / 2;
        int max_sum = 0;
        int curr_sum = 0;

        for (int i = 1; i <= k_len; i++) {
            curr_sum += b[i];
        }
        max_sum = curr_sum;

        for (int i = k_len + 1; i <= N; i++) {
            curr_sum += b[i] - b[i - k_len];
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
            }
        }
        printf("%d\n", max_sum);
    }
    return 0;
}