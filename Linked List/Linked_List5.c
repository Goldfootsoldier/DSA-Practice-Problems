#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_Data(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete_Alt(struct node **head) {
    if (*head == NULL) return;
    struct node *a = *head;
    struct node *b = (*head)->next;

    while (a != NULL && b != NULL) {
        a->next = b->next;
        free(b);
        a = a->next;
        if (a != NULL) {
            b = a->next;
        } else {
            b = NULL;
        }
    }
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, i;
    struct node *head = NULL;
    if (scanf("%d", &n) != 1) return 0;
    for (i = 1; i <= n; i++) {
        insert_Data(&head, i);
    }
    delete_Alt(&head);
    display(head);
    return 0;
}