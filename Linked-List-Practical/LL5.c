/*
Problem Statement

Write a C program to insert a new node at the beginning of a singly linked list created using user input.

After insertion, display the updated linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* insertatBeginning(Node* head, int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;

    head = newNode;

    return head;
}

void traverse(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        head = insertatBeginning(head, value);
    }

    printf("Updated List: ");
    traverse(head);

    return 0;
}