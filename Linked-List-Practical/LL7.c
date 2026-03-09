/*
Problem 6 — Insert a Node at a Given Position
Problem Statement

Write a C program to insert a new node at a specified position in a singly linked list created using user input.

After insertion, display the updated linked list.

Example

Initial list:

10 → 20 → 40 → NULL

Insert 30 at position 3

Result:

10 → 20 → 30 → 40 → NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int value){
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertATEnd(Node* head, int value){
    Node* newNode = createNode(value);

    if(head==NULL)
    return newNode;

    Node* temp = head;

    while(temp->next!=NULL)
        temp = temp->next;
    
    temp->next = newNode;
    return head;
}

Node* insertATPosition(Node* head, int value, int pos)
{
    Node* newNode = createNode(value);

    if(pos == 1)
    {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;

    for(int i = 1; i < pos-1; i++)
    {
        if(temp == NULL)
        {
            printf("Invalid Position\n");
            return head;
        }

        temp = temp->next;
    }

    newNode->next = temp->next;
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

int main() {
    Node* head= NULL;
    int value, pos, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        head = insertATEnd(head, value);
    }

    printf("Original List: ");
    traverse(head);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &pos);

    head = insertATPosition(head, value, pos);

    printf("Updated List: ");
    traverse(head);
    
    return 0;
}