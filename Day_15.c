/*Problem: Given a matrix, calculate the sum of its primary diagonal elements.
 The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each*/

#include <stdio.h>

int main() {
    int m, n;
    
    // Input rows and columns
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    
    // Input matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    
    // Sum of primary diagonal
    int limit = (m < n) ? m : n;
    
    for(int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }
    
    // Output result
    printf("%d", sum);
    
    return 0;
}
