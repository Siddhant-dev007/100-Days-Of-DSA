/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with
dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)*/

#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct node {
    int data;
    struct node *next;
};

// Insert at end
struct node* insertEnd(struct node* head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Count occurrences of key
int countOccurrences(struct node* head, int key) {
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, value, key;
    struct node* head = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Input key
    scanf("%d", &key);

    // Count occurrences
    int result = countOccurrences(head, key);

    // Output result
    printf("%d", result);

    return 0;
}