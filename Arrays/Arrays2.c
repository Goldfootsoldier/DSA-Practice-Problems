#include <stdio.h>
int min(int a, int b) {
    return (a < b) ? a : b;
}

void printSpiralPattern(int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int top_dist = i;
            int bottom_dist = r - 1 - i;
            int left_dist = j;
            int right_dist = c - 1 - j;
            int layer = min(min(top_dist, bottom_dist), min(left_dist, right_dist));
            if (layer % 2 == 0) {
                printf("Y ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int ROWS, COLS;
    if (scanf("%d %d", &ROWS, &COLS) == 2) {
        printSpiralPattern(ROWS, COLS);
    }
    return 0;
}
