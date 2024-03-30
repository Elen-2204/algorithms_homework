#define _CRT_SECURE_N_WARNINGS
#include <stdio.h>


int LinSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
int main(void)
{
    int arr[] = { 2, 10, 4, 50, 72 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    int result = LinSearch(arr, N, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}