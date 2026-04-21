#include<stdio.h>

#define MAX 100

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int value)
{
    if(rear==MAX-1)
    {
        printf("Overflow\n");
        return;
    }

    if(front==-1)
        front=0;

    rear++;

    queue[rear]=value;
}

void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n",queue[front]);

    front++;
}

void display()
{
    if(front==-1 || front>rear)
    {
        printf("Empty\n");
        return;
    }

    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);

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