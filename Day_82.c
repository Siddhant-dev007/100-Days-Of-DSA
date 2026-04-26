/*Problem Statement:
Given a sorted array, find:
- Lower Bound: index of first element >= target
- Upper Bound: index of first element >  target
If not found, return the size of array.

Input Format:
- First line contains N and target
- Second line contains N sorted integers*/

#include <stdio.h>

// First index where arr[i] >= target
int lowerBound(int arr[], int n, int target) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else                   hi = mid;
    }
    return lo;
}

// First index where arr[i] > target
int upperBound(int arr[], int n, int target) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= target) lo = mid + 1;
        else                    hi = mid;
    }
    return lo;
}

int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Lower Bound index: %d\n", lowerBound(arr, n, target));
    printf("Upper Bound index: %d\n", upperBound(arr, n, target));
    return 0;
}
