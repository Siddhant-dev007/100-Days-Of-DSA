/*Problem Statement:
Find the winner of an election. Given candidate votes, print the candidate
who received the maximum votes. If there is a tie, print the one with the
smaller index/name.

Input Format:
- First line contains N (number of votes)
- Second line contains N candidate names (strings)*/

#include <stdio.h>
#include <string.h>

#define MAX_CAND 100
#define MAX_NAME 50

int main() {
    int n;
    scanf("%d", &n);

    char votes[1000][MAX_NAME];
    char candidates[MAX_CAND][MAX_NAME];
    int  count[MAX_CAND] = {0};
    int  numCandidates = 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);

        // Check if candidate already seen
        int found = 0;
        for (int j = 0; j < numCandidates; j++) {
            if (strcmp(candidates[j], votes[i]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(candidates[numCandidates], votes[i]);
            count[numCandidates] = 1;
            numCandidates++;
        }
    }

    int maxIdx = 0;
    for (int i = 1; i < numCandidates; i++)
        if (count[i] > count[maxIdx])
            maxIdx = i;

    printf("Winner: %s with %d votes\n", candidates[maxIdx], count[maxIdx]);
    return 0;
}
