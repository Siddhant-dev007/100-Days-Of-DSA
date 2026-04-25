/*Problem Statement:
Implement Bubble Sort algorithm to sort an array in ascending order.
Print the array after each pass.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers*/

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp  = arr[j];
                arr[j]    = arr[j + 1];
                arr[j + 1]= temp;
                swapped   = 1;
            }
        }
        printf("Pass %d: ", i + 1);
        for (int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");
        if (!swapped) break; // already sorted
    }
}

int main() {
    int n; scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
