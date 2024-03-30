#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
    int size;
} CircularQueue;


void initQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(CircularQueue* queue) {
    return queue->size == 0;
}

int isFull(CircularQueue* queue) {
    return queue->size == MAX_SIZE;
}


void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. \n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
    queue->size++;
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    queue->size--;
    return value;
}

int peek(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->data[queue->front];
}

int main() {
    CircularQueue queue;
    initQueue(&queue);

    int size;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size.\n", MAX_SIZE);
        return 1;
    }

    srand(time(NULL));

    printf("\nGenerated Circular Queue Elements: \n");
    for (int i = 0; i < size; i++) {
        int random_number = rand() % 1000;
        enqueue(&queue, random_number);
        printf("%d ", random_number);
    }
    printf("\n");

    printf("\nFront element: %d\n", peek(&queue));

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Front element after dequeue: %d\n", peek(&queue));

    return 0;
}
