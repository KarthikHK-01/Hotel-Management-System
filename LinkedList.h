#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list
{
    char name[50];
    char comment[100];
    int rating;
    struct list* link;
};
typedef struct list list;

list* addnode(char name[])
{
    list *temp;
    temp=malloc(sizeof(list));
     char comment[100];
         int rating;
    printf("\nEnter your feedback (max 100 characters): ");
        scanf(" %[^\n]", comment);
    strncpy(temp->comment, comment, sizeof(temp->comment) - 1);
            temp->comment[sizeof(temp->comment) - 1] = '\0';
    // Get rating from the user (1 - Poor, 2 - Fair, 3 - Good, 4 - Very Good, 5 - Excellent)
        printf("Rate your feedback from 1 (Poor) to 5 (Excellent): ");
        scanf("%d", &rating);
         if (rating < 1 || rating > 5) 
            printf("Invalid rating! Please enter a rating between 1 and 5.\n");
        temp->rating=rating;
        strncpy(temp->name, name, sizeof(temp->name) - 1);
            temp->name[sizeof(temp->name) - 1] = '\0';

    temp->link=NULL;
    return temp;
}
list* append(list* temp,char name[])
{
    list* traverse=temp;
    list* p=addnode(name);
    if(temp==NULL)
    {
        temp=p;
    }
    else{
        while (traverse->link!=NULL)
        {
            traverse=traverse->link;
        }
        traverse->link=p;
        
    }
    return temp;
}
void Display_Linked_List(list *Temp)
{
list *Traverse = Temp;
if(Traverse==NULL)
{
    printf("\n No feedbacks [no one checked out]");

}
else
{
    while(Traverse!=NULL)
    {
        printf("\nName:%s\n",Traverse->name);
        printf("Comment: %s\n", Traverse->comment);
        printf("Rating: %d\n", Traverse->rating);
         printf("\n");
    Traverse=Traverse->link;
    }
}
}