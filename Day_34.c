/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct node *temp;
    int val;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int evaluate(char postfix[])
{
    int i = 0;
    int op1, op2, result;

    while(postfix[i] != '\0')
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(postfix[i])
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }
        i++;
    }

    return pop();
}

int main()
{
    char postfix[100];
    int result;

    scanf("%s", postfix);

    result = evaluate(postfix);

    printf("%d", result);

    return 0;
}