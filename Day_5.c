/*Problem: A system receives two separate logs of user arrival times from two 
different servers. Each log is already sorted in ascending order. 
Your task is to create a single chronological log that preserves the correct order 
of arrivals.*/

#include <stdio.h>
int main() {
    int p, q;
    int i = 0, j = 0;

    scanf("%d", &p);
    int log1[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    scanf("%d", &q);
    int log2[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    // Merge and print
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    // Remaining elements of log1
    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    // Remaining elements of log2
    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    return 0;
}
