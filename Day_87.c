/*Problem Statement:
Implement Binary Search (Iterative) on a sorted array.
Return the index of the target element, or -1 if not found.

Input Format:
- First line contains N and target
- Second line contains N sorted integers*/

#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if      (arr[mid] == target) return mid;
        else if (arr[mid] <  target) lo = mid + 1;
        else                         hi = mid - 1;
    }
    return -1;
}

int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int result = binarySearch(arr, n, target);
    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found\n", target);
    return 0;
}
