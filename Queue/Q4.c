#include<stdio.h>

int s1[100];
int s2[100];

int top1=-1;
int top2=-1;

void enqueue(int x)
{
    s1[++top1]=x;
}

void dequeue()
{
    if(top1==-1 && top2==-1)
    {
        printf("Empty\n");
        return;
    }

    if(top2==-1)
    {
        while(top1!=-1)
            s2[++top2]=s1[top1--];
    }

    printf("Deleted: %d\n",s2[top2--]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    return 0;
}