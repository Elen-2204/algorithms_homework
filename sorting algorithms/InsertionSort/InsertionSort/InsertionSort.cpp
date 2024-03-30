#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(double* A, int n) {
    for (int i = 1; i < n; ++i) {
        double key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
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
    clock_t start_time = clock();
    printf("Generating random array...\n");
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        arr[i] = (double)rand() / RAND_MAX;
        printf("%.2lf", arr[i]);
    }

   

    

    insertion_sort(arr, n);

    clock_t end_time = clock();
       double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("The sorted array is:\n");
    for (int i = 0; i < n; ++i) {
        printf("%lf ", arr[i]);
    }
    printf("\n");

    printf("Execution time: %.9lf seconds\n", execution_time);
    free(arr);

    

    return 0;
}
