/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory
allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key*/

#include <stdio.h>
#include <stdlib.h>

// Define structure
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

// Delete first occurrence of key
struct node* deleteFirstOccurrence(struct node* head, int key) {
    struct node *temp = head, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL)
        return head;

    // Unlink node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Print list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value, key;
    struct node* head = NULL;

    // Input size
    scanf("%d", &n);

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Input key
    scanf("%d", &key);

    // Delete first occurrence
    head = deleteFirstOccurrence(head, key);

    // Print updated list
    printList(head);

    return 0;
}