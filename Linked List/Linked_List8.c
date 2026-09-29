#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create(struct node **head, int data) {
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

void print(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

struct node* reverse(struct node* head) {
    struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void fold(struct node *head) {
    if (head == NULL || head->next == NULL) return;
    struct node *slow = head, *fast = head, *prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != NULL) {
        prev = slow;
        slow = slow->next;
    }
    prev->next = NULL;

    struct node *second = reverse(slow);
    struct node *first = head;

    while (second != NULL) {
        struct node *t1 = first->next;
        struct node *t2 = second->next;

        first->next = second;
        if (t1 == NULL) break;
        second->next = t1;

        first = t1;
        second = t2;
    }
}

int main() {
    int n, i, val;
    struct node *head = NULL;
    if (scanf("%d", &n) != 1) return 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        create(&head, val);
    }
    printf("Link list data:");
    print(head);
    fold(head);
    printf("Link list data after fold:");
    print(head);
    return 0;
}