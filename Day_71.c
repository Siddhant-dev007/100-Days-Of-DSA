/*Problem Statement:
Implement a Hash Table using Quadratic Probing for collision resolution.
Support insert and search operations.

Input Format:
- First line contains table size and number of keys to insert
- Second line contains N space-separated keys
- Third line contains number of search queries
- Fourth line contains the search keys*/

#include <stdio.h>
#define EMPTY -1
#define DELETED -2

int hashTable[1000];
int tableSize;

void initTable() {
    for (int i = 0; i < tableSize; i++)
        hashTable[i] = EMPTY;
}

int hashFunc(int key) {
    return key % tableSize;
}

void insert(int key) {
    int index = hashFunc(key);
    int i = 0;

    while (i < tableSize) {
        int newIndex = (index + i * i) % tableSize;

        if (hashTable[newIndex] == EMPTY || hashTable[newIndex] == DELETED) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }
    printf("Table is full, cannot insert %d\n", key);
}

int search(int key) {
    int index = hashFunc(key);
    int i = 0;

    while (i < tableSize) {
        int newIndex = (index + i * i) % tableSize;

        if (hashTable[newIndex] == key) return newIndex;
        if (hashTable[newIndex] == EMPTY) return -1;
        i++;
    }
    return -1;
}

void printTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}

int main() {
    int n;
    scanf("%d %d", &tableSize, &n);

    initTable();

    int keys[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
        insert(keys[i]);
    }

    printTable();

    int q;
    scanf("%d", &q);
    printf("\nSearch Results:\n");
    while (q--) {
        int key;
        scanf("%d", &key);
        int idx = search(key);
        if (idx != -1)
            printf("Key %d found at index %d\n", key, idx);
        else
            printf("Key %d not found\n", key);
    }

    return 0;
}
