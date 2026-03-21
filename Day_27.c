/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic
memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list */

#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct node {
    int data;
    struct node* next;
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

// Get intersection point
struct node* getIntersection(struct node* head1, struct node* head2) {
    if (head1 == NULL || head2 == NULL)
        return NULL;

    struct node* p1 = head1;
    struct node* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }

    return p1;  // NULL if no intersection
}

int main() {
    int n, m, value;
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    struct node* intersection = getIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}