#include <stdio.h>

int queue[100];
int front = -1, rear = -1;

void enqueue(int data, int l) {
    if (front == -1) front = 0;
    queue[++rear] = data;
}

void reverse() {
    for (int i = front, j = rear; i < j; i++, j--) {
        int temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
    }
}

int main() {
    int n, t;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        enqueue(t, n);
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    reverse();

    printf("Reversed Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    return 0;
}