/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory
allocation.

Input:
- First line: integer n
- Second line: n space-separated integers*/

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i, x;
    struct node *head = NULL, *temp, *newnode;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;

        if(head == NULL) {
            head = newnode;
            newnode->next = head;
            temp = head;
        }
        else {
            temp->next = newnode;
            newnode->next = head;
            temp = newnode;
        }
    }

    // Traversal
    temp = head;
    for(i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}