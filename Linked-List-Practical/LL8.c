#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

/* create node */
Node* createNode(int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* build list */
Node* insertAtEnd(Node* head, int value)
{
    Node* newNode = createNode(value);

    if(head == NULL)
        return newNode;

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

/* traverse */
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

/* reverse */
Node* reverseList(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{
    Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    /* building list */
    for(int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        head = insertAtEnd(head, value);
    }

    printf("Original List:\n");
    traverse(head);

    head = reverseList(head);

    printf("Reversed List:\n");
    traverse(head);

    return 0;
}