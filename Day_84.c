/*Problem Statement:
Implement Insertion Sort algorithm to sort an array in ascending order.
Print the array after each pass.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers*/

#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j   = i - 1;

        // Shift elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");
    }
}

int main() {
    int n; scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    insertionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
