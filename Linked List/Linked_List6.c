#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int GetNth(struct node* head, int index) {
    struct node* current = head;
    int count = 1;
    while (current != NULL) {
        if (count == index)
            return current->data;
        count++;
        current = current->next;
    }
    return -1;
}

void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node* head) {
    struct node* temp = head;
    printf("Linked list:->");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("-->");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, i, val, index;
    struct node* head = NULL;
    if (scanf("%d", &n) != 1) return 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&head, val);
    }
    scanf("%d", &index);
    printList(head);
    printf("Node at index =%d:%d\n", index, GetNth(head, index));
    return 0;
}