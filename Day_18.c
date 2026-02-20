/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k*/

#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    
    // Input size
    scanf("%d", &n);
    
    int arr[n];
    
    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input k
    scanf("%d", &k);
    
    // Handle k > n
    k = k % n;
    
    // Reverse method (Optimal O(n))
    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
    
    // Output result
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
