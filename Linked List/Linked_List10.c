#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *newNode, *temp;
    int i, val;
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void deleteD(int d) {
    int i;
    struct node *temp;
    for (i = 0; i < d; i++) {
        if (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
}

void display() {
    struct node *temp = head;
    printf("Linked List:->");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, d;
    if (scanf("%d", &n) != 1) return 0;
    create(n);
    scanf("%d", &d);
    deleteD(d);
    display();
    return 0;
}