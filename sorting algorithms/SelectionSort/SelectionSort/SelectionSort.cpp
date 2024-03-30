#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selection_sort(double* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index =i;
		for (int j = i + 1; j < n; j++) {
			if (j < min_index) min_index = j;

		}
        double temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

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

    printf("Generating array...\n");
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &arr[i]);
    }
    printf("\n");

    //clock_t start_time = clock();

    selection_sort(arr, n);

//clock_t end_time = clock();
    //double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

printf("The sorted array is:\n");
for (int i = 0; i < n; ++i) {
    printf("%lf ", arr[i]);
}
printf("\n");

    free(arr);

   // printf("Execution time: %.9lf seconds\n", execution_time);

    return 0;
}