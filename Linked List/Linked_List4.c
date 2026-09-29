#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void create(int n) {
    struct node *newNode, *temp;
    int data, i;
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insertBefore(int P, int X) {
    struct node *p1, *p2, *temp;
    if (start == NULL) return;
    
    if (start->data == P) {
        p1 = (struct node*)malloc(sizeof(struct node));
        p1->data = X;
        p1->next = start;
        start = p1;
        return;
    }

    p2 = start;
    while (p2->next != NULL && p2->next->data != P) {
        p2 = p2->next;
    }

    if (p2->next == NULL) {
        printf("Node not found!\n");
    } else {
        p1 = (struct node*)malloc(sizeof(struct node));
        p1->data = X;
        p1->next = p2->next;
        p2->next = p1;
    }
}

void display() {
    struct node *temp = start;
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
    int n, P, X;
    if (scanf("%d", &n) != 1) return 0;
    create(n);
    scanf("%d", &P);
    scanf("%d", &X);
    insertBefore(P, X);
    display();
    return 0;
}