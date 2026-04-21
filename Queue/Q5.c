#include <stdio.h>
#include <stdlib.h>

/* Queue Node */
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

/* Stack Node */
typedef struct Stack{
    int data;
    struct Stack* next;
}Stack;

Stack* top = NULL;

/* Queue enqueue */
void enqueue(int value)
{
    Node* newNode = malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

/* Queue dequeue */
int dequeue()
{
    if(front == NULL)
        return -1;

    Node* temp = front;

    int value = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);

    return value;
}

/* Stack push */
void push(int value)
{
    Stack* newNode = malloc(sizeof(Stack));

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

/* Stack pop */
int pop()
{
    if(top == NULL)
        return -1;

    Stack* temp = top;

    int value = temp->data;

    top = top->next;

    free(temp);

    return value;
}

/* Display Queue */
void display()
{
    Node* temp = front;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("\n");
}

/* Reverse first K elements */
void reverseK(int k)
{
    int i;

    /* Step 1: move K elements to stack */
    for(i=0;i<k;i++)
    {
        push(dequeue());
    }

    /* Step 2: push back to queue */
    while(top != NULL)
    {
        enqueue(pop());
    }

    /* Step 3: move remaining elements */
    int size = 0;

    Node* temp = front;

    while(temp != NULL)
    {
        size++;
        temp = temp->next;
    }

    for(i=0;i<size-k;i++)
    {
        enqueue(dequeue());
    }
}

int main()
{
    int k;

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    printf("Original Queue:\n");

    display();

    printf("Enter K: ");
    scanf("%d",&k);

    reverseK(k);

    printf("Updated Queue:\n");

    display();

    return 0;
}