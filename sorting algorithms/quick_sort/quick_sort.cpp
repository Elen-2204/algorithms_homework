#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;        

    for (int j = low; j <= high - 1; j++) {
        
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }
}

int main() {
    
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    

  

    printf("Generated Array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  
        printf("%d ", arr[i]);
    }
    printf("\n");

    quick_sort(arr, 0, n - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
