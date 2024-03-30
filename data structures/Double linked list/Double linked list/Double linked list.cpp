#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAtBeginning(Node** head, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void deleteNode(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = *head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    if (current == NULL) {
        printf("not found in the list.\n", value);
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    else {
        *head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

Node* search(Node* head, int value) {
    Node* current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    return current;
}

void displayList(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid size. \n");
        return 1;
    }

    srand(time(NULL));

    printf("\nGenerated List Elements: \n");
    for (int i = 0; i < size; i++) {
        int random_number = rand() % 1000;
        insertAtEnd(&head, random_number);
        printf("%d ", random_number);
    }
    printf("\n");

    insertAtBeginning(&head, 999);
    insertAtEnd(&head, 888);

    printf("\nAfter Insertion: ");
    displayList(head);

    int searchValue;
    printf("\nEnter a value to search in the list: ");
    scanf("%d", &searchValue);
    Node* foundNode = search(head, searchValue);
    if (foundNode != NULL) {
        printf("Node with value %d found in the list.\n", searchValue);
    }
    else {
        printf("Node with value %d not found in the list.\n", searchValue);
    }

    int deleteValue;
    printf("\nEnter a value to delete from the list: ");
    scanf("%d", &deleteValue);
    deleteNode(&head, deleteValue);

    printf("\nAfter Deletion: ");
    displayList(head);

    Node* current = head;
    while (current != NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}
