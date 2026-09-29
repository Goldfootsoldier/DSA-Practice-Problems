#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int empty() {
    return top == -1;
}

int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    if (char1 == '{' && char2 == '}') return 1;
    if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

int main() {
    char exp[MAX];
    if (scanf("%s", exp) != 1) return 0;
    int i = 0;
    int isBalanced = 1;
    while (exp[i]) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (empty() || !isMatchingPair(pop(), exp[i])) {
                isBalanced = 0;
                break;
            }
        }
        i++;
    }
    if (!empty()) isBalanced = 0;
    if (isBalanced) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}