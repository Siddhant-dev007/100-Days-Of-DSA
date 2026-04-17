/*Problem Statement:
Find the first non-repeating character in a given string.
If all characters repeat, print -1.

Input Format:
- A single string (no spaces)*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[10000];
    scanf("%s", str);

    int freq[256] = {0};
    int len = strlen(str);

    // Count frequency of each character
    for (int i = 0; i < len; i++)
        freq[(int)str[i]]++;

    // Find first character with frequency 1
    for (int i = 0; i < len; i++) {
        if (freq[(int)str[i]] == 1) {
            printf("First non-repeating character: %c (index %d)\n", str[i], i);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
