#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct mystack {
    Node* head;
} mystack;
mystack* createStack() {
    mystack* ms = (mystack*)malloc(sizeof(mystack));
    ms->head = NULL;
    return ms;
}
void push(int data, mystack* ms) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = ms->head;
    ms->head = newNode;
}
int pop(mystack* ms) {
    if (ms == NULL || ms->head == NULL) return -1;
    Node* temp = ms->head;
    int val = temp->data;
    ms->head = ms->head->next;
    free(temp);
    return val;
}
void merge(mystack* ms1, mystack* ms2) {
    if (ms1 == NULL || ms1->head == NULL) {
        ms1->head = ms2->head;
        return;
    }   
    Node* temp = ms1->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ms2->head;
}
void display(mystack* ms) {
    Node* current = ms->head;
    int first = 1;
    while (current != NULL) {
        if (!first) {
            printf(" ");
        }
        printf("%d", current->data);
        first = 0;
        current = current->next;
    }
    printf("\n");
}
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    mystack* ms1 = createStack();
    mystack* ms2 = createStack();
    int* arr1 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    int* arr2 = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < n; i++) {
        push(arr1[i], ms1);
    }
    for (int i = 0; i < m; i++) {
        push(arr2[i], ms2);
    }
    merge(ms1, ms2);
    display(ms1);
    free(arr1);
    free(arr2);
    return 0;
}