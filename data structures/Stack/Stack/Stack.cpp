#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;


void initStack(Stack* stack) {
    stack->top = -1;
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}


int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}


void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Error: Stack is full.\n");
        return;
    }
    stack->data[++stack->top] = value;
}


int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return -1; 
    }
    return stack->data[stack->top--];
}


int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return -1; 
    }
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    initStack(&stack);

    int size;
    printf("Enter the size of the stack (up to %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size.\n", MAX_SIZE);
        return 1;
    }

    srand(time(NULL));

    printf("\nGenerated Stack Elements: \n");
    for (int i = 0; i < size; i++) {
        int random_number = rand() % 1000; 
        push(&stack, random_number);
        printf("%d ", random_number);
    }
    printf("\n");

    printf("\nTop element: %d\n", top(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Top element after pop: %d\n", top(&stack));

    return 0;
}
