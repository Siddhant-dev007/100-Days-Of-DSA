/*Problem Statement:
Implement a Hash Table using Separate Chaining (linked list) for collision resolution.
Support insert, search and delete operations.

Input Format:
- First line contains table size and number of operations
- Each operation: I key (insert), S key (search), D key (delete)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int key;
    struct Node* next;
};

struct Node* table[MAX];
int tableSize;

int hashFunc(int key) {
    return ((key % tableSize) + tableSize) % tableSize;
}

void insert(int key) {
    int index = hashFunc(key);
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key  = key;
    node->next = table[index];
    table[index] = node;
    printf("Inserted %d at index %d\n", key, index);
}

void search(int key) {
    int index = hashFunc(key);
    struct Node* curr = table[index];
    while (curr) {
        if (curr->key == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        curr = curr->next;
    }
    printf("Key %d not found\n", key);
}

void deleteKey(int key) {
    int index = hashFunc(key);
    struct Node* curr = table[index];
    struct Node* prev = NULL;

    while (curr) {
        if (curr->key == key) {
            if (prev) prev->next = curr->next;
            else       table[index] = curr->next;
            free(curr);
            printf("Deleted key %d\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Key %d not found for deletion\n", key);
}

void printTable() {
    printf("\nHash Table (Separate Chaining):\n");
    for (int i = 0; i < tableSize; i++) {
        printf("[%d] -> ", i);
        struct Node* curr = table[i];
        while (curr) {
            printf("%d -> ", curr->key);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n;
    scanf("%d %d", &tableSize, &n);

    for (int i = 0; i < tableSize; i++) table[i] = NULL;

    for (int i = 0; i < n; i++) {
        char op;
        int key;
        scanf(" %c %d", &op, &key);

        if      (op == 'I') insert(key);
        else if (op == 'S') search(key);
        else if (op == 'D') deleteKey(key);
    }

    printTable();
    return 0;
}
