#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

struct roomstructure
{
    int roomID;
    int status;
    char customerName[20];
};

struct roomstructure Room[MAX] = 
{
          {1,0,"Nil"},
          {2,0,"Nil"},
          {3,0,"Nil"},
          {4,0,"Nil"},
          {5,0,"Nil"}

};
//______________________________________________________________________________________

void listoccupiedRooms(struct roomstructure *p)
{
          int i,placeholder=0;
          printf("listOccupiedRooms():\n");
          for (i=0;i<MAX;i++)
          {
                    if ((*(p+i)).status != 0)
                    {
                              placeholder=1;
                              printf("roomID: %d\n", (*(p+i)).roomID);
                              printf("customer name: %s", (*(p+i)).customerName);
                    }
          }
          if (placeholder==0)
          {
                    printf("The hotel is empty\n");
          }
}
//______________________________________________________________________________________

int assignRoom(struct roomstructure *p)
{
          int roomNumber,i,placeholder=1;
          printf("assignRoom():\n");


//Check if Hotel is full
          for (i=0;i<MAX;i++)
          {
                    if ((*(p+i)).status==0)
                    {
                              placeholder = 0;
                    }
          }
          if (placeholder==1)
          {
                    printf("The hotel is full\n");
                    return 0;
          }
          
          printf("Enter a roomID between 1 and 5:\n"); 
                                        
//Check if room number is between 1 and 5
          scanf("%d", &roomNumber);
          while ((roomNumber>5) || (roomNumber<1))
          {
                    printf("Enter a roomID between 1 and 5:\n");
                    scanf("%d", &roomNumber);
          } 

//Check if Room is Occupied          
          while ((*(p+roomNumber-1)).status==1)
          {
                    printf("Occupied! Enter another roomID\n");
                    printf("Enter a roomID between 1 and 5:\n");
                    scanf("%d", &roomNumber);
          }
//Assign Room to guest
          

          printf("Enter customer name:\n");
          scanf("\n");
          fgets((*(p+roomNumber-1)).customerName,20,stdin);
          (*(p+roomNumber-1)).status = 1;
          printf("The room has been assigned successfully\n");


          return 0;
}
//______________________________________________________________________________________

int removeRoom(struct roomstructure *p)
{
          int roomNumber,i,placeholder=0;
          printf("removeRoom():\n");

//Check if Hotel is empty
          for (i=0;i<MAX;i++)
          {
                    if ((*(p+i)).status==1)
                    {
                              placeholder = 1;
                    }
          }
          if (placeholder==0)
          {
                    printf("All the rooms are empty\n");
                    return 0;
          }

          printf("Enter a roomID between 1 and 5:\n");
                                        
//Check if room number is between 1 and 5
          scanf("%d", &roomNumber);
          while ((roomNumber>5) || (roomNumber<1))
          {
                    printf("Enter a roomID between 1 and 5:\n");
                    scanf("%d", &roomNumber);
          } 

//Check if Room is Empty         
          while ((*(p+roomNumber-1)).status==0)
          {
                    printf("Empty! Enter another roomID for removal\n");
                    printf("Enter a roomID between 1 and 5:\n");
                    scanf("%d", &roomNumber);
          }
//Remove room
          
          
          (*(p+roomNumber-1)).status = 0;
          strcpy((*(p+roomNumber-1)).customerName, "Nil");
          printf("Removal is successful\n");

          

          return 0;
}

//______________________________________________________________________________________

int findCustomer(struct roomstructure *p)
{

          struct roomstructure RoomCopy[MAX] = 
          {
                    {1,0,"Nil"},
                    {2,0,"Nil"},
                    {3,0,"Nil"},
                    {4,0,"Nil"},
                    {5,0,"Nil"}

          };
          
          
          int i,j;
          char target[20];
          printf("findCustomer():\n");
          printf("Enter customer name:\n");
          scanf("\n");
          fgets(target,20,stdin);
          //Copy contents of Room into RoomCopy
          for (i=0;i<MAX;i++)
          {
                    RoomCopy[i].roomID = Room[i].roomID;
                    RoomCopy[i].status = Room[i].status;
                    strcpy(RoomCopy[i].customerName, Room[i].customerName);

          }
          
          
          //Change all names in the RoomCopy to lowercase
          for (i=0;i<MAX;i++)
          {
                    for (j=0;RoomCopy[i].customerName[j]!='\0';j++)
                    {
                              RoomCopy[i].customerName[j] = tolower(RoomCopy[i].customerName[j]);
                    }
          }
          //Change target name to lowercase
          for (i=0;target[i]!='\0';i++)
          {
                    target[i] = tolower(target[i]);
          }
          //Check if target name matches any name in the RoomCopy
          for (i=0;i<MAX;i++)
          {
                    if (strcmp(RoomCopy[i].customerName, target)==0)
                    {
                              printf("The target customer name is found\n");
                              printf("roomID: %d\n", (*(p+i)).roomID);
                              printf("customer name: %s", (*(p+i)).customerName);
                              return 0;
                    }
          }
          printf("The target customer name is not found\n");
          return 0;
}


int main()
{
          int choice;
          printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
          printf("1: listOccupiedRooms()\n");
          printf("2: assignRoom()\n");
          printf("3: removeRoom()\n");
          printf("4: findCustomer()\n");
          printf("5: quit\n");
          
          do
          {
                    printf("Enter your choice:\n");
                    scanf("%d", &choice);
                    switch(choice)
                    {
                              case 1:
                                        listoccupiedRooms(Room);
                                        break;
                              case 2:
                                        assignRoom(Room);
                                        break;
                              case 3:
                                        removeRoom(Room);
                                        break;
                              case 4:
                                        findCustomer(Room);
                                        break;

                    }
          } while (choice!=5);

          
          
}
