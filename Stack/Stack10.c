#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][100];
int top = -1;

void push(char* str) {
    strcpy(stack[++top], str);
}

void pop(char* str) {
    strcpy(str, stack[top--]);
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void postToPre(char* post_exp, char* result) {
    int length = strlen(post_exp);
    for (int i = 0; i < length; i++) {
        if (isOperator(post_exp[i])) {
            char op1[100], op2[100], temp[200];
            pop(op2);
            pop(op1);
            temp[0] = post_exp[i];
            temp[1] = '\0';
            strcat(temp, op1);
            strcat(temp, op2);
            push(temp);
        } else {
            char temp[2] = {post_exp[i], '\0'};
            push(temp);
        }
    }
    strcpy(result, stack[top]);
}

int main() {
    char post_exp[100];
    char pre_exp[200];
    if (scanf("%s", post_exp) != 1) return 0;
    postToPre(post_exp, pre_exp);
    printf("%s\n", pre_exp);
    return 0;
}