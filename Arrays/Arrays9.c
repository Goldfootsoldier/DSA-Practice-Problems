#include <stdio.h>
#include <stdbool.h>
int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;
    int matrix[m][n];
    bool row_has_one[m];
    bool col_has_one[n];
    for (int i = 0; i < m; i++) 
        row_has_one[i] = false;
    for (int j = 0; j < n; j++) 
        col_has_one[j] = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 1) {
                row_has_one[i] = true;
                col_has_one[j] = true;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row_has_one[i] || col_has_one[j]) {
                printf("1");
            } else {
                printf("0");
            }
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}