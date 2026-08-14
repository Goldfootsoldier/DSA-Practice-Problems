#include <stdio.h>
const char *LOOKUP[4][10] = {
    {"", "B", "BB", "BBB", "BW", "W", "WB", "WBB", "WBBB", "BZ"},
    {"", "Z", "ZZ", "ZZZ", "ZP", "P", "PZ", "PZZ", "PZZZ", "ZB"},
    {"", "B", "BB", "BBB", "BG", "G", "GB", "GBB", "GBBB", "BR"},
    {"", "R", "RR", "RRR"}
};
void convertToMartian(int num) {
    printf("%s%s%s%s\n", 
           LOOKUP[3][num / 1000],
           LOOKUP[2][(num % 1000) / 100],
           LOOKUP[1][(num % 100) / 10],
           LOOKUP[0][num % 10]);
};
int main() {
    int num;
    while (scanf("%d", &num) == 1) {
        if (num >= 1 && num <= 3999) {
            convertToMartian(num);
        } else {
            printf("Error: Number out of range (1-3999)\n");
        }
    }
    return 0;
}
