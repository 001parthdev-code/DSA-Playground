/*
Problem 1 — Valid Parentheses (Balanced Brackets)

This is the foundational stack problem because it teaches when to push and when to pop.

Problem Statement

Given a string containing only:

( ) { } [ ]

Determine whether the string is valid.

A string is valid if:

Every opening bracket has a matching closing bracket.

Brackets close in the correct order.

Every closing bracket corresponds to the most recent unmatched opening bracket.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node* next;
}Node;

Node* top = NULL;

void push(char c)
{
    Node* newNode = malloc(sizeof(Node));

    newNode->data = c;
    newNode->next = top;

    top = newNode;
}

char pop()
{
    if(top == NULL)
        return '#';

    Node* temp = top;

    char value = temp->data;

    top = top->next;

    free(temp);

    return value;
}

int isValid(char str[])
{
    for(int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }

        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(top == NULL)
                return 0;

            char popped = pop();

            if((ch == ')' && popped != '(') ||
               (ch == '}' && popped != '{') ||
               (ch == ']' && popped != '['))
            {
                return 0;
            }
        }
    }

    if(top == NULL)
        return 1;

    return 0;
}

int main()
{
    char str[100];

    printf("Enter expression: ");
    scanf("%s", str);

    if(isValid(str))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}
