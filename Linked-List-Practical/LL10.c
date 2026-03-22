#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

/* Create node */
Node* createNode(int value)
{
    Node* newNode = malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

/* Insert at end */
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

/* Traverse */
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

/* Remove nth from end */
Node* removeNthFromEnd(Node* head, int n)
{
    Node* slow = head;
    Node* fast = head;

    /* Move fast n steps */
    for(int i=0;i<n;i++)
        fast = fast->next;

    /* Delete head case */
    if(fast == NULL)
    {
        Node* temp = head;

        head = head->next;

        free(temp);

        return head;
    }

    /* Move both */
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    /* Delete */
    Node* temp = slow->next;

    slow->next = slow->next->next;

    free(temp);

    return head;
}

int main()
{
    Node* head = NULL;

    head = insertAtEnd(head,1);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,5);

    printf("Original list:\n");

    traverse(head);

    head = removeNthFromEnd(head,2);

    printf("After deletion:\n");

    traverse(head);

    return 0;
}