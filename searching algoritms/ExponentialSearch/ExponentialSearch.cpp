#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
#define min

int BinSearch(int arr[], int left, int right, int key)
{
    int mid, midvalue;
    while (left <= right)
    {
        mid = (left + right) / 2;
        midvalue = arr[mid];
        if (key == midvalue) return mid;
        else if (key < midvalue) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;

    return BinSearch(arr, i / 2, min(i, n - 1), x);
}

int main(void)
{
    int arr[] = { 2, 4, 5, 7, 10, 67 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    int result = exponentialSearch(arr, n, x);
    (result == -1) ? printf("Element is not present in array")
        : printf("Element is present at index % d",result);
    return 0;
}