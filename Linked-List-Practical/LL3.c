#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtEnd(Node* head, int value)
{
    Node* newNode = malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

void printList(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
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

    printList(head);

    return 0;
}