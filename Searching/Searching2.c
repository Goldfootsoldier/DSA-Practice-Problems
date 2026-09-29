#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXP 100
#define BUFLEN 105

char *gems[] = {"NONE", "Garnet", "Amethyst", "Aquamarine", "Diamond", "Emerald", "Pearl", "Ruby", "Peridot", "Sapphire", "Tourmaline", "Topaz", "Lapis", 0};
char ponies[MAXP][BUFLEN];
int gem_rank[MAXP];

int get_gem_rank(const char *name) {
    int max_rank = 0;
    for (int i = 1; gems[i] != 0; i++) {
        const char *p = name;
        while ((p = strstr(p, gems[i])) != NULL) {
            int before_ok = (p == name || *(p - 1) == ' ');
            int after_ok = (*(p + strlen(gems[i])) == '\0' || *(p + strlen(gems[i])) == ' ');
            if (before_ok && after_ok) {
                if (i > max_rank) {
                    max_rank = i;
                }
            }
            p++;
        }
    }
    return max_rank;
}

int compare(int a, int b) {
    if (gem_rank[a] != gem_rank[b]) {
        return gem_rank[b] - gem_rank[a];
    }
    return strcmp(ponies[a], ponies[b]) > 0;
}

int main() {
    int count = 0;
    while (1) {
        char buf[BUFLEN];
        if (!fgets(buf, sizeof(buf), stdin)) break;
        buf[strcspn(buf, "\r\n")] = 0;
        if (strcmp(buf, "END") == 0) break;
        if (strlen(buf) > 0) {
            strcpy(ponies[count], buf);
            gem_rank[count] = get_gem_rank(buf);
            count++;
        }
    }

    int order[MAXP];
    for (int i = 0; i < count; i++) order[i] = i;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare(order[j], order[j + 1]) > 0) {
                int temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s\n", ponies[order[i]]);
    }

    return 0;
}