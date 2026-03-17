#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

/* PUSH */
void push(int value)
{
    Node* newNode = malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

/* POP */
void pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    Node* temp = top;

    printf("Popped: %d\n", temp->data);

    top = top->next;

    free(temp);
}

/* PEEK */
void peek()
{
    if(top == NULL)
    {
        printf("Stack empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

/* DISPLAY */
void display()
{
    Node* temp = top;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    peek();

    return 0;
}