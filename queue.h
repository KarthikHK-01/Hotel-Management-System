#include<stdio.h>
#include<stdlib.h>
#define SIZE 100


typedef struct NODE
{
    int queue[SIZE];
    int front,rear;
}node;


void enqueue(int n,node *ptr)
{
    if(ptr->rear==(SIZE-1))
    {
        printf("Overflow");
    }
    else if (ptr->front == -1 && ptr->rear == -1)
    {
        ptr->front=ptr->rear=0;
        ptr->queue[ptr->front]=n;
    }
    else{
        ptr->rear++;
        ptr->queue[ptr->rear]=n;
    }
}

void display(node *ptr)
{
    if (ptr->front == -1 || ptr->rear == -1)
    {
        printf("No element present\n");
    }
    else{
    for (int i=ptr->front;i<=ptr->rear;i++)
    {
        printf("%d\t",ptr->queue[i]);
    }
     printf("\n");
    }

}
int dequeue(node *ptr)
{
    int x=ptr->queue[ptr->front];
    if(ptr->front==-1 && ptr->rear==-1)
    {
        printf("\nNo element to delete UNDERFLOW");
        return 0;
    }
    else if(ptr->front == ptr->rear)
    {
        //printf("\nThe deleted element is --> %d\n",ptr->queue[ptr->front]);
        ptr->front = ptr->rear =-1;
        return x;
    }
    else{
    //printf("\nThe deleted element is --> %d\n",ptr->queue[ptr->front]);
    ptr->front ++;
    return x;
    }
}