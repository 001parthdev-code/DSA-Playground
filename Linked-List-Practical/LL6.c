/*
Problem 5 — Insert at End of Linked List

This one is very important because it combines:

traversal

insertion

pointer linking

and it appears in almost every DSA exam.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

/* Create a new node */
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtEnd(Node* head, int value) 
{
    Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

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

        head = insertAtEnd(head, value);
    }

    printf("Updated List: ");
    traverse(head);

    return 0;
}