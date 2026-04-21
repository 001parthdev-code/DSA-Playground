#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node* next;
}Node;

Node* push(Node* top,char value)
{
    Node* newNode=malloc(sizeof(Node));

    newNode->data=value;
    newNode->next=top;

    return newNode;
}

Node* pop(Node* top)
{
    if(top==NULL)
        return NULL;

    Node* temp=top;

    top=top->next;

    free(temp);

    return top;
}

int isEmpty(Node* top)
{
    if(top==NULL)
        return 1;

    return 0;
}

int main()
{
    char str[100];

    Node* top=NULL;

    printf("Enter expression: ");

    scanf("%s",str);

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(')
        {
            top=push(top,str[i]);
        }

        else if(str[i]==')')
        {
            if(isEmpty(top))
            {
                printf("Invalid\n");
                return 0;
            }

            top=pop(top);
        }
    }

    if(isEmpty(top))
        printf("Valid\n");

    else
        printf("Invalid\n");

    return 0;
}