/*Problem Statement:
Implement Selection Sort algorithm to sort an array in ascending order.
Print the array after each pass.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers*/

#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;

        // Swap minimum with current position
        if (minIdx != i) {
            int temp     = arr[i];
            arr[i]       = arr[minIdx];
            arr[minIdx]  = temp;
        }

        printf("Pass %d: ", i + 1);
        for (int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");
    }
}

int main() {
    int n; scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    selectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
