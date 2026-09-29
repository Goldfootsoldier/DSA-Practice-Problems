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

void del(int pos, int n) {
    int i;
    struct node *p1;
    if (pos <= 1 || pos > n) {
        printf("Invalid Node! ");
        return;
    }
    for (i = 1; i < pos; i++) {
        if (head != NULL) {
            p1 = head;
            head = head->next;
            free(p1);
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
    int n, pos;
    if (scanf("%d", &n) != 1) return 0;
    create(n);
    scanf("%d", &pos);
    del(pos, n);
    display();
    return 0;
}