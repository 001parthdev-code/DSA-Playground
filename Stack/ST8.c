#include<stdio.h>

int main()
{
    int arr[100];
    int stack[100];

    int n,top=-1;

    printf("Enter size: ");
    scanf("%d",&n);

    printf("Enter elements:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(int i=0;i<n;i++)
    {
        while(top!=-1 && stack[top]<arr[i])
        {
            printf("%d -> %d\n",stack[top],arr[i]);

            top--;
        }

        stack[++top]=arr[i];
    }

    while(top!=-1)
    {
        printf("%d -> -1\n",stack[top]);
        top--;
    }

    return 0;
}