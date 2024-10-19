#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "queue.h"
#include "binaryinorder.h"
#include "stacks.h"
#include "sorting.h"
#include "LinkedList.h"
#include <time.h>
    // Get current time
    time_t currentTime;
    struct tm *localTime;

   
node nq;
list* Linkedlist;
    int count=50;
    int occ=0;
    int z;
    int customers=0;
 struct checkingin
    {
        int d;
        int m;
        int h;
        int mm;
    };
struct reserve
{
    
    char name[50];
    int count;
    int list;
    int numadu;
    int numchil;
    int nights;
    int roomnumber[10];
    int totroom;
    struct checkingin date;
    // struct reserve* link;
     
    
};
typedef struct reserve res;
struct Date ww[50];
res resverations[100];
int rooms[50];
int stackrooms[50];
void room()
{
    FILE *fp= fopen("rooms.txt", "r"); // Replace "example.csv" with your CSV file name

    if (fp == NULL) {
        perror("Error opening file");
        
    }

   // int array[100];
    
    char line[1000]; // Adjust the size based on your maximum line length
    int i = 0;
    //int j = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, ",");
        while (token != NULL) {
            //printf("%s\n",token);
            if(atoi(token)>100)
             rooms[i] = atoi(token);
            
           // printf("%d\n",atoi(token));
           //printf("%d\n",array[i]);
            token = strtok(NULL, ",");
            i++;
        }
        
    }

        fclose(fp);



    // Printing the array for verification
    for (int w = 0; w <i; w++) {
      {
            printf("%d ", rooms[w]);
        }
        printf("\n");
    }
    
}
void updateDuplicateNames(res *names, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(names[i].name, names[j].name) == 0) {
                
                int len = strlen(names[i].name) + 1;  // +1 for the null terminator
                char *id = malloc(len + 2);  // +2 for the number and null terminator

                
                strcpy(id, names[i].name);

                
                id[len - 1] = (char)((names[i].count+1) + '0');
                id[len] = '\0';

               
               strncpy(names[j].name, id,len);   // Set the duplicate name to the new name
                names[i].count++;     
            }
        }
    }
}
void sortedroom(int floor)
{
    int sortedArray[10];
    
    sortedArray[0]=floor*100+5;
    //printf("%d\n",sortedArray[0]);
    int j=1;
    for(int i=1;i<10;i=i+2)
        {
            if(i==9)
            {
            sortedArray[i]=sortedArray[0]+j;
            break;
            }
            sortedArray[i]=sortedArray[0]-j;
        j++;
        } 
        j=1;  
          for(int i=2;i<10;i=i+2)
         {
            sortedArray[i]=sortedArray[0]+j;
            j++;
        } 
        for(int i=0;i<10;i++)
            printf("%d\n",sortedArray[i]);

    
    int n=10;
    //printf("%d\n",n);
    //sortedArrayToBST(sortedArray,0,9);

    // Convert the sorted array to a binary search tree
    struct TreeNode* root = sortedArrayToBST(sortedArray, 0, n - 1);

    // Perform in-order traversal to verify the construction
    printf("In-order traversal of the constructed BST: ");
    inOrderTraversal(root);
    for(int j=0;j<10;j++)
        printf("\nW%d\n",arr[j]);
}
void stackroom()
{
   
    int k=0;
    
    for(int floor=1;floor<=5;floor++)
    {
        sortedroom(floor);
        for(int i=floor*10-1;i>=(floor-1)*10;i--)
            stackrooms[k++]=arr[i];
    }
    for(int i=0;i<50;i++)
        printf("%d ",stackrooms[i]);
}
 int i=0;
void assignroom(int n)
{
    top=49;
    nq.front=-1;
    nq.rear=-1;
    
     for (int i = 0; i < n; i++) {
        ww[i].hour=resverations[i].date.h;
        ww[i].date=resverations[i].date.d;
        ww[i].month=resverations[i].date.m;
        ww[i].si=resverations[i].list;
    }
    bubbleSort(ww,n);
    printf("Sorted Array of Dates:\n");
    for (int i = 0; i < n; i++) {
        printf("%dh-%dd-%dm, %d\n", ww[i].hour, ww[i].date, ww[i].month,ww[i].si);
    }
    for(int i=0;i<n;i++)
    {
        enqueue(ww[i].si,&nq);
    }
    display(&nq);
    int ee;
    int ppl;
    if(nq.rear<50 )
    {
    for(int p=nq.front;p<=nq.rear;p++)
    {
        //printf("%d",dequeue(&nq));
        ee=dequeue(&nq)-1;//for direct index [index starts from 0 slno starts from 1]
        ppl=resverations[ee].numadu+((resverations[ee].numchil/2));
        printf("%d\t",ppl);
        resverations[ee].totroom=ceil((double)ppl/4);
        printf("\n%d\t",resverations[ee].totroom);
        if(resverations[ee].totroom>count)
        {
            printf("\n%s Your reservation is on hold, due to unavailability of rooms",resverations[ee].name);
            break;
        }
        customers++;
        printf("\n%s\n",resverations[ee].name);

        for(int q=0;q<resverations[ee].totroom;q++)
            {
                resverations[ee].roomnumber[q]=pop(stackrooms);
                printf("\n\t%d\t",resverations[ee].roomnumber[q]);
                count--;
                occ++;
            }

    }
    printf("\nTotal rooms avialble:%d",count);  
    printf("\nTotal rooms occupied:%d",occ);  
    }
}
void reserveroom()
{
    FILE *file;
    char filename[] = "new.txt";
    //char name[MAX_NAME_LENGTH];
    char line[100];

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        //return 1;
    }

    // Read and print the name column
   
    while (fgets(line, sizeof(line), file) != NULL) {
        // Tokenize the line based on commas
        char *token = strtok(line, ",");
        resverations[i].list=atoi(token);
        printf("%d\n",resverations[i].list);
         token=strtok(NULL,",");
        
        // Extract and print the name column
        if (token != NULL) {
            
            strncpy(resverations[i].name, token, sizeof(resverations[i].name) - 1);
            resverations[i].name[sizeof(resverations[i].name) - 1] = '\0'; // Null-terminate the string
            printf("Name: %s  %d\n", resverations[i].name,i);
            
        }
        
        token=strtok(NULL,",");
         if (token != NULL) {
            //printf("%s\n",token);
            resverations[i].numadu = atoi(token);
            //printf("%d\n",atoi(token)); 
            printf("Number of adults: %d  %d\n", resverations[i].numadu,i);
            
        }
           token=strtok(NULL,",");
         if (token != NULL) {
            
            resverations[i].numchil = atoi(token); // Null-terminate the string
            printf("Name: %d  %d\n", resverations[i].numchil,i);
            
        }
        
        token=strtok(NULL,",");
         if (token != NULL) {
            
            resverations[i].nights = atoi(token); // Null-terminate the string
            printf("Nights: %d  %d\n", resverations[i].nights,i);
            
        }
        char str1[11];
        token=strtok(NULL,",");
         if (token != NULL) {
         strncpy(str1,token,11);
         printf("%s",str1);   
            resverations[i].date.d = (str1[0]-48)*10+(str1[1]-48); // Null-terminate the string
            printf("\ndate: %d  %d\n", resverations[i].date.d,i);
           if((int)str1[3]-48==0)
           {
            resverations[i].date.m =str1[4]-48 ;
            printf("\nmonth: %d  %d\n", resverations[i].date.m,i);
           }
            else
           {
            resverations[i].date.m =10+(str1[4]-48) ;
            printf("month: %d  %d\n", resverations[i].date.m,i);
           }

        }
        char str2[6];
        token=strtok(NULL,",");
         if (token != NULL) {
         strncpy(str2,token,6);
         printf("%s",str2);   
            resverations[i].date.h = (str2[0]-48)*10+(str2[1]-48); // Null-terminate the string
            printf("\nhour: %d  %d\n", resverations[i].date.h,i);
           
           
            resverations[i].date.mm =(str2[3]-48)*10+(str2[4]-48) ;
            printf("min: %d  %d\n", resverations[i].date.mm,i);
         }
         resverations[i].count=0;
         
       i++;
       
       
       }
        z=i-1;
        updateDuplicateNames(resverations,i);
       assignroom(i);
       fclose(file);
}

void newReservation() {
    // File pointer
    FILE *csvFile;

    // Open the CSV file in write mode
    csvFile = fopen("new.txt", "r+");  // Use "a" for append mode

    // Check if the file was opened successfully
    if (csvFile == NULL) {
        printf("Error opening the file.\n");
        return; // Exit the function
    }

    // Sample data to be written to the CSV file
    int slno;
    char nam[50];
    int adults;
    int children;
    int nonights;
    char data[11];
  
    char time[7];
    int lineCount = 0;
    int choice;

    // Read the file line by line
    char buffer[100];  // Adjust the buffer size as needed
    while (fgets(buffer, sizeof(buffer), csvFile) != NULL) {
        lineCount++;
    }
    printf("_______________________%d_______________",lineCount);
    slno = lineCount + 1;

    printf("\nEnter the name of the customer: ");
    scanf(" %[^\n]s", nam);  // Add a space before %[^\n] to consume the newline character
    printf("%s", nam);

    printf("\nEnter the number of adults: ");
    scanf("%d", &adults);

    printf("\nEnter the number of children: ");
    scanf("%d", &children);

    printf("\nEnter the number of nights the customer wants to stay: ");
    scanf("%d", &nonights);

    printf("\nEnter the check-in date in DD/MM/YYYY format: ");
    scanf(" %[^\n]s", data);  // Add a space before %[^\n] to consume the newline character
    printf("%s", data);

    printf("\nChoose a check-in time:\n1: 08:30\n2: 12:30\n3: 16:30\n4: 20:30\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strncpy(time, "08:30", sizeof(time) - 1);
            time[sizeof(time) - 1] = '\0';
            break;
        case 2:
            strncpy(time, "12:30", sizeof(time) - 1);
            time[sizeof(time) - 1] = '\0';
            break;
        case 3:
            strncpy(time, "16:30", sizeof(time) - 1);
            time[sizeof(time) - 1] = '\0';
            break;
        case 4:
            strncpy(time, "20:30", sizeof(time) - 1);
            time[sizeof(time) - 1] = '\0';
            break;
        default:
            printf("Invalid choice");
            fclose(csvFile);  // Close the file before returning
            return;
    }

    // Write data to the CSV file
    fprintf(csvFile, "%d,%s,%d,%d,%d,%s,%s,\n", slno, nam, adults, children, nonights, data, time);

    // Close the CSV file
    fclose(csvFile);

    printf("Data has been written to the CSV file successfully.\n");
}
void checkIn()
{
     // Get current time in seconds since epoch
    time(&currentTime);

    // Convert the current time to the local time structure
    localTime = localtime(&currentTime);
    z=z+1;
    printf("%d",z);
    resverations[z].list=z+1;
    char name[50];
    resverations[z].count=0;
    printf("\nEnter the name of the customer: ");
    scanf(" %[^\n]s", name);  // Add a space before %[^\n] to consume the newline character
    strncpy(resverations[z].name, name, sizeof(resverations[z].name) - 1);
            resverations[z].name[sizeof(resverations[z].name) - 1] = '\0'; // Null-terminate the string
            updateDuplicateNames(resverations,z+1);
            printf("Name: %s  %d\n", resverations[z].name,z);
    
    printf("\nEnter the number of adults: ");
    scanf("%d", &resverations[z].numadu);

    printf("\nEnter the number of children: ");
    scanf("%d", &resverations[z].numchil);

    printf("\nEnter the number of nights the customer wants to stay: ");
    scanf("%d", &resverations[z].nights);
    resverations[z].date.d=localTime->tm_mday;
    resverations[z].date.m=localTime->tm_mon + 1;
    int hour=localTime->tm_hour;    
    if(hour>8 && hour<13)
    {
        resverations[z].date.h=12;
        resverations[z].date.mm=30;
    }
     else if(hour>12 && hour<17)
    {
        resverations[z].date.h=16;
        resverations[z].date.mm=30;
    }
    else if(hour>16)
    {
        resverations[z].date.h=20;
        resverations[z].date.mm=30;
    }
     else
     {
        resverations[z].date.h=8;
        resverations[z].date.mm=30;
    }
    printf("\n\n%d/%d/%d\n\n",resverations[z].date.d,resverations[z].date.h,resverations[z].date.m);
    int ppl=resverations[z].numadu+((resverations[z].numchil/2));
        printf("%d\t",ppl);
        resverations[z].totroom=ceil((double)ppl/4);
        printf("\n%d\t",resverations[z].totroom);
        if(resverations[z].totroom>count)
        {
            printf("\n%s Your reservation is on hold, due to unavailability of rooms",resverations[z].name);
            return;
        }
        customers++;
        printf("\n%s\n",resverations[z].name);

        for(int q=0;q<resverations[z].totroom;q++)
            {
                resverations[z].roomnumber[q]=pop(stackrooms);
                printf("\n\t%d\t",resverations[z].roomnumber[q]);
                count--;
                occ++;
            }

    printf("\nCustomers: %d",customers);
    printf("\nTotal rooms avialble:%d",count);  
    printf("\nTotal rooms occupied:%d",occ);  

    
}
void checkOut() {
    char customerName[50];
    int roomprice = 2500;
    printf("\nEnter the name of the customer checking out: ");
    scanf(" %[^\n]", customerName);
    customerName[sizeof(customerName) - 1] = '\0';

    for (int i = 0; i < customers; i++) {
        if (strcmp(customerName, resverations[i].name) == 0) {
            double bill = (roomprice * resverations[i].nights)*resverations[i].totroom;
            printf("\nThe rooms you checked in during your stay are:\n");
            for (int k = 0; k < resverations[i].totroom; k++) {
                printf("%d\t", resverations[i].roomnumber[k]);
                push(resverations[i].roomnumber[k], stackrooms);
                count++;
                occ--;
            }
            printf("Customer Name: %s\nNights: %d\nNumber of rooms: %d\nTotal Bill: Rs.%.2lf\n", resverations[i].name, resverations[i].nights,resverations[i].totroom ,bill);
            Linkedlist= append(Linkedlist,resverations[i].name);

            for (int j = i; j < customers - 1; j++) {
                resverations[j] = resverations[j + 1];
            }

            customers--;
            printf("\n\n");
            return;
        }
    }
    printf("\nCustomer not found [Enter correct name]");
    printf("\n\n");
}
void getAvailableRooms() {
    printf("Available Rooms:\n");
    displaystack(stackrooms);
    printf("\n\n");
    
}
void searchCustomer() {
    char cusname[50];
     printf("\nEnter the name of the customer checking out: ");
    scanf(" %[^\n]", cusname);
    cusname[sizeof(cusname) - 1] = '\0';

    for (int i = 0; i < customers; i++) {
        if (strcmp(cusname, resverations[i].name) == 0){
            printf("Customer found:\n");
             printf("\nThe rooms the customer has occupied are:\n");
            for (int k = 0; k < resverations[i].totroom; k++) 
                printf("%d\t", resverations[i].roomnumber[k]);
             printf("\nCustomer Name: %s\nNights: %d\nNumber of rooms:%d\n", resverations[i].name, resverations[i].nights,resverations[i].totroom);
             printf("\nThe number of adults: %d\tThe number of children are: %d",resverations[i].numadu,resverations[i].numchil);
             printf("\n\n");
            return;
        }
    }
    
    printf("Customer not found.\n");
    printf("\n\n");
}
void generateGuestSummaryReport() {
    printf("\nGuest Summary Report:\n");
    for (int i = 0; i < customers; i++) {
        printf("\nCustomer Name: %s\nNights: %d\nNumber of rooms:%d\n", resverations[i].name, resverations[i].nights,resverations[i].totroom);
             printf("\nThe number of adults: %d\tThe number of children are: %d",resverations[i].numadu,resverations[i].numchil);
        printf("\nThe rooms the customer has occupied are:\n");
            for (int k = 0; k < resverations[i].totroom; k++) 
                printf("%d\t", resverations[i].roomnumber[k]);
        printf("\nCheck in date is: %d/%d/2023",resverations[i].date.d,resverations[i].date.m);
        printf("\n_________________________________________________________\n");
    }
    printf("\n\n");
}


int main()
{
    printf("\n%d\n",customers);
    printf("Welcome to KALKH hotel");
    room();
    stackroom();
    int n;
    char response;

    printf("Do you want to execute the code? (y/n): ");
    scanf(" %c", &response); // Note the space before %c to consume any leading whitespace

    if (response == 'y' || response == 'Y') {
        // Your code to be executed when 'y' is input
        printf("Executing the code...\n");
    printf("\n\nEnter the number of new reservations");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        newReservation();
    printf("\n\nThe Reservations List is updated and no new reservation can now be added");
    }
    printf("\n\n\nThe assignment of rooms for those who are in the list will take place:\n\n\n");
    reserveroom();
    int choice;
    while (1)
    {
        printf("\nHotel Management System\n");
        printf("1. Check-Out\n");
        printf("2. Check-In Onspot\n");
        printf("3. Get Available Rooms\n");
        printf("4. Search Customer\n");
        printf("5. Generate Guest Summary Report\n");
        printf("6. Print all the feedbacks from the respective customers\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
           
            case 1:
                checkOut();
                break;
            case 2:
            
                checkIn();
                break;
            case 3:
                getAvailableRooms();
                break;
            case 4:
                searchCustomer();
                break;
            case 5:
                generateGuestSummaryReport();
                break;
            case 6:
                Display_Linked_List(Linkedlist);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
 

    return 0; 
}
