#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int A[309][309];
bool ok[309][309][309];

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int R, C, L;
        scanf("%d %d %d", &R, &C, &L);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%d", &A[i][j]);
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int min_val = A[i][j];
                int max_val = A[i][j];
                for (int k = j; k < C; k++) {
                    if (A[i][k] < min_val) min_val = A[i][k];
                    if (A[i][k] > max_val) max_val = A[i][k];
                    ok[i][j][k] = (max_val - min_val <= L);
                }
            }
        }

        int max_area = 0;
        for (int j = 0; j < C; j++) {
            for (int k = j; k < C; k++) {
                int curr_h = 0;
                for (int i = 0; i < R; i++) {
                    if (ok[i][j][k]) {
                        curr_h++;
                        int area = curr_h * (k - j + 1);
                        if (area > max_area) max_area = area;
                    } else {
                        curr_h = 0;
                    }
                }
            }
        }
        printf("%d\n", max_area);
    }
    return 0;
}