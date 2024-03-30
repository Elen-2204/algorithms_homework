#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// //iterative Way
int BinSearch(int arr[], int n, int left, int right, int key)
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

////recursive way
//int BinSearch(int arr[], int n, int left, int right, int key)
//{
//    int mid, midvalue;
//    if (left > right) return -1;
//    else {
//        mid = (left + right) / 2;
//        midvalue = arr[mid];
//    }
//    if (key == midvalue) return mid;
//    else if (key < midvalue) return BinSearch(arr, n, left, mid - 1, key);
//    else return BinSearch(arr, n, mid + 1, right, key);
//}



int main(void)
{
    int arr[] = { 2, 5,7,10, 45, 70, 83 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = BinSearch(arr,n, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array"):printf("Element is present at index %d",result);
    return 0;
}
