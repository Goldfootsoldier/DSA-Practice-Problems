#include <stdio.h>
#include <string.h>

#define CMDS 5
#define MAXWORDS 50
#define BUFLEN 1000

int cl[CMDS];
char lists[CMDS][MAXWORDS][100];
char *tokens[4] = {"[N]", "[AV]", "[V]", "[AJ]"};
char *cmds[CMDS] = {"NOUNS", "ADVERBS", "VERBS", "ADJECTIVES", "END"};

int main() {
    char story[BUFLEN];
    if (!fgets(story, sizeof(story), stdin)) return 0;
    story[strcspn(story, "\r\n")] = 0;

    char line[100];
    int current_cmd = -1;

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\r\n")] = 0;
        if (strcmp(line, "END") == 0) break;

        int found = 0;
        for (int i = 0; i < 4; i++) {
            if (strcmp(line, cmds[i]) == 0) {
                current_cmd = i;
                found = 1;
                break;
            }
        }
        if (!found && current_cmd != -1) {
            strcpy(lists[current_cmd][cl[current_cmd]++], line);
        }
    }

    int ptrs[4] = {0, 0, 0, 0};

    for (int pass = 0; pass < 2; pass++) {
        char temp_story[BUFLEN];
        strcpy(temp_story, story);

        for (int i = 0; i < 4; i++) {
            char *pos;
            while ((pos = strstr(temp_story, tokens[i])) != NULL) {
                char new_story[BUFLEN];
                int prefix_len = pos - temp_story;
                strncpy(new_story, temp_story, prefix_len);
                new_story[prefix_len] = '\0';
                strcat(new_story, lists[i][ptrs[i]++]);
                strcat(new_story, pos + strlen(tokens[i]));
                strcpy(temp_story, new_story);
            }
        }
        printf("%s\n", temp_story);
    }

    return 0;
}