/*Problem Statement:
Check whether a given array represents a valid Min-Heap.
In a Min-Heap, every parent node must be less than or equal to its children.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers*/

#include <stdio.h>

int isMinHeap(int arr[], int n) {
    // Check every internal node
    for (int i = 0; i <= (n / 2) - 1; i++) {
        int left  = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left])
            return 0;

        if (right < n && arr[i] > arr[right])
            return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isMinHeap(arr, n))
        printf("Yes, it is a Min-Heap\n");
    else
        printf("No, it is not a Min-Heap\n");

    return 0;
}
