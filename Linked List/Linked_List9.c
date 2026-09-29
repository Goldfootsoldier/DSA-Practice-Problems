#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n *next;
};

struct n *head = NULL;

void insert(int data) {
    struct n *newNode = (struct n*)malloc(sizeof(struct n));
    struct n *temp;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void display(struct n *h) {
    struct n *temp = h;
    printf("[h] =>");
    if (h != NULL) {
        do {
            printf("%d=>", temp->data);
            temp = temp->next;
        } while (temp != h);
    }
    printf("[h]\n");
}

void splitAndDisplay(int n) {
    struct n *oddHead = NULL, *evenHead = NULL;
    struct n *oddTail = NULL, *evenTail = NULL;
    struct n *temp = head;
    int i;
    
    for (i = 1; i <= n; i++) {
        struct n *newNode = (struct n*)malloc(sizeof(struct n));
        newNode->data = temp->data;
        newNode->next = NULL;
        
        if (i % 2 != 0) {
            if (oddHead == NULL) {
                oddHead = newNode;
                oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
            oddTail->next = oddHead;
        } else {
            if (evenHead == NULL) {
                evenHead = newNode;
                evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
            evenTail->next = evenHead;
        }
        temp = temp->next;
    }

    printf("Complete linked_list:\n");
    display(head);
    printf("Odd:\n");
    display(oddHead);
    printf("Even:\n");
    display(evenHead);
}

int main() {
    int n, i;
    if (scanf("%d", &n) != 1) return 0;
    for (i = 1; i <= n; i++) {
        insert(i);
    }
    splitAndDisplay(n);
    return 0;
}