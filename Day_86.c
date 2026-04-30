/*Problem Statement:
Find the floor of the square root of a given number N using Binary Search.
Do not use the sqrt() library function.

Input Format:
- A single integer N*/

#include <stdio.h>

long long sqrtBinarySearch(long long n) {
    if (n < 2) return n;

    long long lo = 1, hi = n / 2, ans = 1;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (mid * mid == n) return mid;
        if (mid * mid < n) { ans = mid; lo = mid + 1; }
        else                  hi = mid - 1;
    }
    return ans;
}

int main() {
    long long n; scanf("%lld", &n);
    printf("Floor of sqrt(%lld) = %lld\n", n, sqrtBinarySearch(n));
    return 0;
}
