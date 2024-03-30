#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} MaxHeap;

void initMaxHeap(MaxHeap* heap) {
    heap->size = 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int index) {
    return (index - 1) / 2;
}

int leftChild(int index) {
    return 2 * index + 1;
}

int rightChild(int index) {
    return 2 * index + 2;
}

void heapifyUp(MaxHeap* heap, int index) {
    while (index > 0 && heap->data[index] > heap->data[parent(index)]) {
        swap(&heap->data[index], &heap->data[parent(index)]);
        index = parent(index);
    }
}

void heapifyDown(MaxHeap* heap, int index) {
    int left = leftChild(index);
    int right = rightChild(index);
    int largest = index;
    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        heapifyDown(heap, largest);
    }
}

void insert(MaxHeap* heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Max Heap is full.\n");
        return;
    }
    heap->data[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        printf(" Max Heap is empty.\n");
        return -1; 
    }
    int max = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return max;
}

int peek(MaxHeap* heap) {
    if (heap->size <= 0) {
        printf("Error: Max Heap is empty. \n");
        return -1;
    }
    return heap->data[0];
}

void increaseKey(MaxHeap* heap, int index, int newValue) {
    if (index < 0 || index >= heap->size) {
        printf("Error: Invalid index.\n");
        return;
    }
    if (newValue <= heap->data[index]) {
        printf("Error: New value must be greater than the current value.\n");
        return;
    }
    heap->data[index] = newValue;
    heapifyUp(heap, index);
}

void display(MaxHeap* heap) {
    printf("Max Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap heap;
    initMaxHeap(&heap);

    int choice, value, index, newValue;

    while (1) {
        printf("\nBinary Max Heap Operations:\n");
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Peek (Maximum)\n");
        printf("4. Increase Key\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert(&heap, value);
            break;
        case 2:
            printf("Extracted Maximum element: %d\n", extractMax(&heap));
            break;
        case 3:
            printf("Maximum element: %d\n", peek(&heap));
            break;
        case 4:
            printf("Enter the index of the key to increase: ");
            scanf("%d", &index);
            printf("Enter the value: ");
            scanf("%d", &newValue);
            increaseKey(&heap, index, newValue);
            break;
        case 5:
            display(&heap);
            break;
        case 6:

            exit(0);
        default:
            printf("Invalid choice! \n");
        }
    }

    return 0;
}
