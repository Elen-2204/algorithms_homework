#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counting_sort(unsigned int A[], unsigned n) {

    unsigned k = A[0];
    for (unsigned i = 1; i < n; i++) {
        if (A[i] > k) {
            k = A[i];
        }
    }

    
    unsigned* C = (unsigned*)malloc((k + 1) * sizeof(unsigned));
    memset(C, 0, (k + 1) * sizeof(unsigned));

    for (unsigned i = 0; i < n; i++) {
        ++C[A[i]];
    }

    for (unsigned j = 1; j <= k; j++) {
        C[j] += C[j - 1];
    }

    
    unsigned* B = (unsigned*)malloc(n * sizeof(unsigned));

    for (int i = n - 1; i >= 0; i--) {
        B[--C[A[i]]] = A[i];
    }

    for (unsigned i = 0; i < n; i++) {
        A[i] = B[i];
    }

    free(B);
    free(C);
}

int main() {
    unsigned n;
    printf("Enter the length of the array: ");
    scanf("%u", &n);

    unsigned int* arr = (unsigned int*)malloc(n * sizeof(unsigned int));

    printf("Generated Array: ");
    for (unsigned i = 0; i < n; i++) {
        arr[i] = rand() % 100;  
        printf("%u ", arr[i]);
    }
    printf("\n");

    counting_sort(arr, n);

    printf("Sorted Array: ");
    for (unsigned i = 0; i < n; i++) {
        printf("%u ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
