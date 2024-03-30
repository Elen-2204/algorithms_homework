#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int interpolationSearch(int arr[], int left, int right, int x)
{
    int pos;
    
    if (left <= right && x >= arr[left] && x <= arr[right]) {
        pos = left+ (((double)(right - left) / (arr[right] - arr[left]))* (x - arr[left]));
        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, right, x);

        if (arr[pos] > x)
            return interpolationSearch(arr, left, pos - 1, x);
    }
    return -1;
}

int main()
{

    int arr[] = { 10, 12, 13, 16, 18,22, 23, 24, 33, 42, 47 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 18;
    int index = interpolationSearch(arr, 0, n - 1, x);

    if (index != -1)
        printf("Element found at index %d", index);
    else
        printf("Element not found.");
    return 0;
}