#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counting_sort(unsigned int A[], unsigned n, unsigned exp) {
    unsigned* C = (unsigned*)malloc(10 * sizeof(unsigned));
    for (unsigned i = 0; i < 10; i++) {
        C[i] = 0;
    }

    for (unsigned i = 0; i < n; i++) {
        ++C[(A[i] / exp) % 10];
    }

    for (unsigned j = 1; j < 10; j++) {
        C[j] += C[j - 1];
    }

    unsigned* B = (unsigned*)malloc(n * sizeof(unsigned));

    for (int i = n - 1; i >= 0; i--) {
        B[--C[(A[i] / exp) % 10]] = A[i];
    }

    for (unsigned i = 0; i < n; i++) {
        A[i] = B[i];
    }

    free(B);
    free(C);
}


void radix_sort(unsigned int A[], unsigned n) {
    int max = A[0];
    for (unsigned i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    for (unsigned exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(A, n, exp);
    }
}

int main() {
    unsigned n;
    printf("Enter the length of the array: ");
    scanf("%u", &n);

    unsigned int* arr = (unsigned int*)malloc(n * sizeof(unsigned int));
    
    printf("\n Generated Array: \n");
    for (unsigned i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  
        printf("%u ", arr[i]);
    }
    printf("\n");

   
    radix_sort(arr, n);

    
    printf("\n Sorted Array: \n");
    for (unsigned i = 0; i < n; i++) {
        printf("%u ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
