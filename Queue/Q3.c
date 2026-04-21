#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* front=NULL;
Node* rear=NULL;

void enqueue(int value)
{
    Node* newNode=malloc(sizeof(Node));

    newNode->data=value;
    newNode->next=NULL;

    if(rear==NULL)
    {
        front=rear=newNode;
        return;
    }

    rear->next=newNode;
    rear=newNode;
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Empty\n");
        return;
    }

    Node* temp=front;

    printf("Deleted: %d\n",front->data);

    front=front->next;

    free(temp);
}

void display()
{
    Node* temp=front;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}