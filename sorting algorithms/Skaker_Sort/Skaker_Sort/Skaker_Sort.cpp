#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void shaker_sort(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    int swapped = 1;

    while (left < right&& swapped) {
        swapped = 0;

        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = 1;
            }
        }
        left++;
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

    shaker_sort(arr, n);

    printf("\nSorted Array: \n");
    for (unsigned i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
