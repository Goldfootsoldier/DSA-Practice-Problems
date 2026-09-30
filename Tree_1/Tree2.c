#include <stdio.h>

int pre[100005];
int in[100005];
int pos[100005];

void printPostOrder(int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return;
    int inIndex = pos[pre[*preIndex]];
    (*preIndex)++;
    printPostOrder(inStart, inIndex - 1, preIndex);
    printPostOrder(inIndex + 1, inEnd, preIndex);
    printf("%d ", in[inIndex]);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int i;
    for (i = 1; i <= n; i++) {
        scanf("%d", &pre[i]);
    }
    for (i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    int preIndex = 1;
    printPostOrder(1, n, &preIndex);
    printf("\n");
    return 0;
}