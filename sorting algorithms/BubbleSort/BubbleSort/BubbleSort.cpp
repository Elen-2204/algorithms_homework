#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(double* xp, double* yp) {
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(double arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}


void printDoubleArray(double arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%.2lf ", arr[i]);
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    double* arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        fprintf(stderr, "Error: failed to allocate memory!\n");
        exit(1);
    }

    printf("Generating random array...\n");
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        arr[i] = (double)rand() / RAND_MAX;
        printf("%.2lf ", arr[i]);
    }
    printf("\n");

    clock_t start_time = clock();

    bubbleSort(arr, n);

    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    printf("The sorted array is:\n");
    printDoubleArray(arr, n);
    printf("\n");

    free(arr);

    printf("Execution time: %.9lf seconds\n", execution_time);

    return 0;
}
