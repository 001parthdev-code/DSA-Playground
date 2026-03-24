#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNewNode(int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

Node* push(Node* top, int value)
{
    Node* newNode = createNewNode(value);
    newNode->next = top;
    top = newNode;
    return top;
}

Node* pop(Node* top)
{
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return NULL;
    }

    Node* temp = top;
    top = top->next;
    free(temp);

    return top;
}

void display(Node* top)
{
    Node* temp = top;

    while(temp!=NULL)
    {
        printf("%d->", temp->data);
        temp= temp->next;
    }
    printf("NULL\n");
}

Node* reverseStack(Node* top)
{
    Node* newTop = NULL;

    while(top!=NULL)
    {
        int value = top->data;

        top = pop(top);
        newTop = push(newTop, value);
    }

    return newTop;
}

int main() {
    Node* top = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(int i=0; i<n;i++)
    {
        printf("Enter the value: ");
        scanf("%d", &value);

        top = push(top,value);
    }

    printf("Original Stack\n");
    display(top);

    top = reverseStack(top);

    printf("Reversed Stack \n");
    display(top);
    
    return 0;
}