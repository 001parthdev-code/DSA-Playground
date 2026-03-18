#include <stdio.h>

# define MAX 100

int stack[MAX];
int top = -1;

void push(int index)
{
    top++;
    stack[top] = index;
}

int pop()
{
    int value = stack[top];
    top--;
    return value;
}

int main()
{
    int arr[] = {4,5,2,10,8};
    int n = 5;

    int result[5];

    for(int i=0;i<n;i++)
        result[i] = -1;

    for(int i=0;i<n;i++)
    {
        while(top != -1 && arr[i] > arr[stack[top]])
        {
            int index = pop();

            result[index] = arr[i];
        }

        push(i);
    }

    printf("Next greater elements:\n");

    for(int i=0;i<n;i++)
        printf("%d ", result[i]);

    return 0;
}