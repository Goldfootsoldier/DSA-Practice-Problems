#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *newNode, *temp;
    int data, i;
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
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

void del(int D) {
    struct node *p1 = head, *p2;
    while (p1 != NULL) {
        if (p1->data == D && p1->next != NULL) {
            p2 = p1->next;
            p1->next = p2->next;
            free(p2);
        } else {
            p1 = p1->next;
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
    int n, D;
    if (scanf("%d", &n) != 1) return 0;
    create(n);
    scanf("%d", &D);
    del(D);
    display();
    return 0;
}l