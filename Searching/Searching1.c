#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 100

int main() {
    char var[3][LEN];
    char inp[3][LEN];
    double M = 0, D = 0, X = 0;
    int missing = -1;

    for (int i = 0; i < 3; i++) {
        if (scanf("%s %s", var[i], inp[i]) != 2) return 0;
        if (inp[i][0] == '?') {
            missing = i;
        } else {
            if (var[i][0] == 'M') M = atof(inp[i]);
            else if (var[i][0] == 'D') D = atof(inp[i]);
            else if (var[i][0] == 'X') X = atof(inp[i]);
        }
    }

    if (var[missing][0] == 'X') {
        X = -M / D;
        printf("x %.2f\n", X);
    } else if (var[missing][0] == 'D') {
        D = -M / X;
        printf("d %.2f\n", D);
    } else if (var[missing][0] == 'M') {
        M = -D * X;
        printf("m %.2f\n", M);
    }

    return 0;
}