#include <stdio.h>
#include <string.h>

int main() {
    char str[1005];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    int count[256] = {0};
    int l = strlen(str);

    for (int i = 0; i < l; i++) {
        if (str[i] != '\n' && str[i] != '\r') {
            count[(unsigned char)str[i]]++;
        }
    }

    int max_freq = 0;
    char best_char = 0;

    for (int i = 0; i < 256; i++) {
        if (count[i] > max_freq) {
            max_freq = count[i];
            best_char = (char)i;
        }
    }

    printf("%c %d\n", best_char, max_freq);
    return 0;
}