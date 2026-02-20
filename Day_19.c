/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers*/

#include <stdio.h>
#include <stdlib.h>

// Function to compare for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Step 1: Sort array
    qsort(arr, n, sizeof(int), compare);
    
    int left = 0;
    int right = n - 1;
    
    int min_sum = 1000000000;
    int x = 0, y = 0;
    
    // Step 2: Two pointer
    while(left < right) {
        int sum = arr[left] + arr[right];
        
        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            x = arr[left];
            y = arr[right];
        }
        
        if(sum < 0)
            left++;
        else
            right--;
    }
    
    // Output
    printf("Elements: %d %d\n", x, y);
    printf("Closest Sum: %d\n", min_sum);
    
    return 0;
}
