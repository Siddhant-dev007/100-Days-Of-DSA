/*Problem: Given an array of integers, count the frequency of each distinct element
and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Frequency count
    for(int i = 0; i < n; i++) {
        int count = 1;

        // Check if already counted
        int alreadyCounted = 0;
        for(int k = 0; k < i; k++) {
            if(arr[i] == arr[k]) {
                alreadyCounted = 1;
                break;
            }
        }

        if(alreadyCounted)
            continue;

        // Count frequency
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        printf("%d -> %d\n", arr[i], count);
    }

    return 0;
}
