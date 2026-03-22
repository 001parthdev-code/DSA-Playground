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
    int n,value,k;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        head = insertAtEnd(head, value);
    }

    printf("\nOriginal List:\n");

    traverse(head);

    printf("\nEnter Nth node from end to delete: ");
    scanf("%d",&k);

    head = removeNthFromEnd(head,k);

    printf("Updated List:\n");

    traverse(head);

    return 0;
}