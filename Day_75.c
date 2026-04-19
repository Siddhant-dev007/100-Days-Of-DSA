/*Problem Statement:
Find the largest subarray with sum equal to zero.
Print the starting and ending index (0-based) of that subarray.
If no such subarray exists, print -1.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

// Hash map entry
struct Entry {
    int sum;
    int index;
    int used;
};

struct Entry hashMap[2 * MAX + 5];
int hashSize = 2 * MAX + 5;

int getHash(int sum) {
    return ((sum % hashSize) + hashSize) % hashSize;
}

void insertMap(int sum, int index) {
    int h = getHash(sum);
    while (hashMap[h].used && hashMap[h].sum != sum)
        h = (h + 1) % hashSize;
    if (!hashMap[h].used) {
        hashMap[h].sum   = sum;
        hashMap[h].index = index;
        hashMap[h].used  = 1;
    }
}

int searchMap(int sum) {
    int h = getHash(sum);
    while (hashMap[h].used) {
        if (hashMap[h].sum == sum)
            return hashMap[h].index;
        h = (h + 1) % hashSize;
    }
    return -2; // not found
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Insert prefix sum 0 at index -1
    insertMap(0, -1);

    int sum = 0;
    int maxLen = 0;
    int startIdx = -1, endIdx = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int prevIdx = searchMap(sum);

        if (prevIdx != -2) {
            int len = i - prevIdx;
            if (len > maxLen) {
                maxLen   = len;
                startIdx = prevIdx + 1;
                endIdx   = i;
            }
        } else {
            insertMap(sum, i);
        }
    }

    if (maxLen == 0)
        printf("-1\n");
    else
        printf("Largest subarray with zero sum: [%d, %d], length = %d\n",
               startIdx, endIdx, maxLen);

    return 0;
}
