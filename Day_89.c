/*Problem Statement:
Allocate Minimum Number of Pages: Given N books with pages[] and M students,
allocate books to students such that:
- Each student gets at least one book
- Books are allocated in contiguous order
- The maximum pages assigned to any student is minimized
Find that minimum possible maximum.

Input Format:
- First line contains N (books) and M (students)
- Second line contains N integers (pages in each book)*/

#include <stdio.h>

// Check if allocation with 'maxPages' limit is possible for 'm' students
int canAllocate(int pages[], int n, int m, int maxPages) {
    int students = 1, pagesSum = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > maxPages) return 0; // single book exceeds limit
        if (pagesSum + pages[i] > maxPages) {
            students++;
            pagesSum = pages[i];
            if (students > m) return 0;
        } else {
            pagesSum += pages[i];
        }
    }
    return 1;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    int pages[1000];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
        sum    += pages[i];
        if (pages[i] > maxVal) maxVal = pages[i];
    }

    if (m > n) { printf("Allocation not possible\n"); return 0; }

    // Binary search: lo = max single book, hi = sum of all books
    int lo = maxVal, hi = sum, ans = sum;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canAllocate(pages, n, m, mid)) { ans = mid; hi = mid - 1; }
        else                                  lo = mid + 1;
    }

    printf("Minimum possible maximum pages: %d\n", ans);
    return 0;
}
