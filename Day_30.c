/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};
int main() {
    int n, i;
    struct node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        scanf("%d %d", &newnode->coeff, &newnode->exp);
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
    // Display polynomial
    temp = head;
    while(temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if(temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    return 0;
}