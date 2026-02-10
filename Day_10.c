/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left, right;
    int flag = 1;

    printf("Enter the string: ");
    scanf("%s", s);   

    left = 0;
    right = strlen(s) - 1;

   
    while (left < right) {
        if (s[left] != s[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}
