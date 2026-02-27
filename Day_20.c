/*Problem: Given an array of integers, count the number of subarrays whose sum is equal
to zero.

Input:
- First line: integer n
- Second line: n integers*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int count = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            if(sum == 0)
                count++;
        }
    }

    printf("Number of zero-sum subarrays = %d", count);

    return 0;
}
