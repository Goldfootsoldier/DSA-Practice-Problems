#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void leastNumberOfTreats() {
    int n;
    scanf("%d", &n);
    int sizes[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &sizes[i]);
    }
    qsort(sizes, n, sizeof(int), compare);
    int total_treats = 0;
    int current_treats = 1;
    total_treats += current_treats;
    for (int i = 1; i < n; i++) {
        if (sizes[i] > sizes[i - 1]) {
            current_treats++;
        }
        total_treats += current_treats;
    }
    printf("%d\n", total_treats);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        leastNumberOfTreats();
    }
    return 0;
}