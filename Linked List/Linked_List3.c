#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void sortedInsert(struct Node** head_ref, struct Node* new_node) {
    struct Node* current;
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else if ((*head_ref)->data >= new_node->data) {
        current = *head_ref;
        while (current->next != *head_ref) {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next != *head_ref && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != head) printf(" ");
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    int n, i, val;
    struct Node* head = NULL;
    if (scanf("%d", &n) != 1) return 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node->next = NULL;
        sortedInsert(&head, new_node);
    }
    printList(head);
    return 0;
}