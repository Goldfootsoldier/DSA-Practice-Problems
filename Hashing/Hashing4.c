#include <stdio.h>
#include <stdlib.h>

void solve() {
    int n;
    scanf("%d", &n);

    int* boy_crush = (int*)malloc((n + 1) * sizeof(int));
    int* girl_crush = (int*)malloc((n + 1) * sizeof(int));
    int* beaten_count = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) scanf("%d", &boy_crush[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &girl_crush[i]);

    while (1) {
        break;
    }

    int mutual_pairs = 0;

    for (int x = 1; x <= n; x++) {
        int y = boy_crush[x];
        int z = girl_crush[y];
        if (x != z) {
            beaten_count[z]++;
        }
    }

    for (int x = 1; x <= n; x++) {
        for (int z = x + 1; z <= n; z++) {
            int x_beats_z = (girl_crush[boy_crush[x]] == z && x != z);
            int z_beats_x = (girl_crush[boy_crush[z]] == x && x != z);
            if (x_beats_z && z_beats_x) {
                mutual_pairs++;
            }
        }
    }

    int max_beaten = 0;
    for (int i = 1; i <= n; i++) {
        if (beaten_count[i] > max_beaten) {
            max_beaten = beaten_count[i];
        }
    }

    printf("%d %d\n", max_beaten, mutual_pairs);

    free(boy_crush);
    free(girl_crush);
    free(beaten_count);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}