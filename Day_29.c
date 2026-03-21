/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory
allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, k, i, x;
    struct node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    scanf("%d", &k);

    if(head == NULL || k == 0) {
        temp = head;
    }
    else {
        int length = 1;
        temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
            length++;
        }

        temp->next = head;  // make circular

        k = k % length;
        int steps = length - k;

        temp = head;
        for(i = 1; i < steps; i++)
            temp = temp->next;

        head = temp->next;
        temp->next = NULL;
    }

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}