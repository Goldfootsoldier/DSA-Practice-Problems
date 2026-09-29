#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (front == -1) front = 0;
    queue[++rear] = data;
}

void dequeue() {
    if (front > rear) return;
    front++;
}

int main() {
    int n, data;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(data);
    }
    printf("Dequeuing elements:\n");
    while (front <= rear) {
        dequeue();
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    }
    return 0;
}