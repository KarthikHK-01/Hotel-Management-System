#include<stdio.h>
#include<stdlib.h>
int top=-1;

int n1;
void push(int  item,int arr[])
{
    if(top==(n1-1))
    {
        printf("\nOVerflow\n");
    }
    else
    {
        top=top+1;
        arr[top]=item;
    }
}
int pop(int arr[])
{ int x;
    if(top==-1)
    printf("\nUnderflow");
    else
    {
        x=arr[top];
        //printf("\nThe room alotted is %d",x);
        top=top-1;
    }
    return x;
}
void displaystack(int arr[])
{
    for(int i=0;i<=top;i++)
    printf("\nThe room number is: %d\n",arr[i]);
    printf("\n_______________");
}