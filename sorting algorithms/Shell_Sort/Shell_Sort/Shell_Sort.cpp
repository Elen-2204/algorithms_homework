#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    unsigned n;
    printf("Enter the length of the array: ");
    scanf("%u", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("\nGenerated Array: \n");
    for (unsigned i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }
    printf("\n");

    shell_sort(arr, n);

    printf("\nSorted Array: \n");
    for (unsigned i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
