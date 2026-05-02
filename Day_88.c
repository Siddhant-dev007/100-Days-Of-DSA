/*Problem Statement:
Aggressive Cows Problem: Given N stalls at positions in a sorted array
and C cows, place cows in stalls such that the minimum distance between
any two cows is maximized. Find that maximum minimum distance.

Input Format:
- First line contains N (stalls) and C (cows)
- Second line contains N stall positions*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place 'cows' cows with at least 'minDist' gap
int canPlace(int stalls[], int n, int cows, int minDist) {
    int count = 1;          // Place first cow in stall[0]
    int last  = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= minDist) {
            count++;
            last = stalls[i];
            if (count == cows) return 1;
        }
    }
    return 0;
}

int main() {
    int n, c; scanf("%d %d", &n, &c);
    int stalls[100000];
    for (int i = 0; i < n; i++) scanf("%d", &stalls[i]);

    qsort(stalls, n, sizeof(int), compare);

    int lo = 1, hi = stalls[n - 1] - stalls[0], ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canPlace(stalls, n, c, mid)) { ans = mid; lo = mid + 1; }
        else                               hi = mid - 1;
    }

    printf("Maximum possible minimum distance: %d\n", ans);
    return 0;
}
