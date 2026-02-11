/*Problem: A secret system stores code names in forward order.
 To display them in mirror format, you must transform the given code name so that
 its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)
in c */

#include <stdio.h>

int main() {
    char str[100];
    int i, len = 0;

    // Input
    scanf("%s", str);

    // Find length of string
    while (str[len] != '\0') {
        len++;
    }

    // Print in reverse order
    for (i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
