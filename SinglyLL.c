// Singly LL

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int Data;
  struct Node *next; 
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void Display(PNODE Head)
{
    printf("Elements of Linked List are :");

    while(Head != 0)
    {
      printf("%d\t", Head -> Data);
      Head = Head-> next;
    }
}

int Count(PNODE Head)
{
  int iCount = 0;

   while(Head != 0)
    {
     iCount++;
      Head = Head-> next;
    }
  return iCount;
}

void InsertFirst(PPNODE Head,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> Data = no;
    newn -> next = NULL;

    if( * Head == NULL)
    {
      *Head = newn;
    } 
    else
    {
      newn ->  next = *Head;
      *Head = newn;
    }
}



void InsertLast(PPNODE Head,int no)
{
       PNODE newn = NULL;
       PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> Data = no;
    newn -> next = NULL;

    if( * Head == NULL)
    {
      *Head = newn;
    } 
    else
    {
       while(temp -> next != NULL)
       {
        temp = temp-> next;
       }
       temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

   if(*Head == NULL)
   {
    return;
   }
   else if((*Head) -> next == NULL)
   {
     free(*Head);
     *Head = NULL;
   }
   else
   {
     *Head = (*Head ) -> next;
     free(temp);
   }
}
void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

   if(*Head == NULL)
   {
    return;
   }
   else if((*Head) -> next == NULL)
   {
     free(*Head);
     *Head = NULL;
   }
   else
   {
    while(temp-> next -> next != NULL)
    {
      temp = temp -> next;
    }
     
     free(temp -> next);
     temp -> next = NULL;
   }  
}
void InsertAtPos(PPNODE Head,int no,int iPos)
{
    int iLength  = 0;
    iLength = Count(*Head);

    PNODE temp = *Head;
    PNODE newn = NULL;
    
    int iCnt = 0;

    if((iPos < 1) || (iPos > iLength +1))
    {
      printf("Invalid Position\n");
      return;
    } 

    if(iPos == 1)
    {
      InsertFirst(Head,no);
    }
    else if(iPos == iLength+1)
    {
      InsertLast(Head,no);
    }
    else
    {
       newn = (PNODE)malloc(sizeof(NODE));

       newn->Data=no;
       newn->next=NULL;

       for(iCnt = 1; iCnt < iPos - 1 ;iCnt++ )
       {
         temp = temp -> next;
       }

       newn->next = temp->next;
       temp->next = newn;

    }
}

void DeleteAtPos(PPNODE Head,int iPos)
{
     
    int iLength  =0;
    iLength= Count(*Head);
    PNODE temp = *Head;
    PNODE tempX = NULL;
    int iCnt = 0;

    if((iPos < 1) || (iPos > iLength ))
    {
      printf("Invalid Position\n");
      return;
    } 

    if(iPos == 1)
    {
      DeleteFirst(Head);
    }
    else if(iPos == iLength)
    {
      DeleteLast(Head);
    }
    else
    {
      

       for(iCnt = 1; iCnt < iPos - 1 ;iCnt++ )
       {
         temp = temp -> next;
       }
       
       tempX = temp -> next;
      temp->next = temp->next->next;
      free(tempX);
       

    }
}



int main()
{PNODE First = NULL;
    int iRet = 0;

    InsertLast(&First, 11);
    InsertLast(&First, 21);
    InsertLast(&First, 51);
    InsertLast(&First, 101);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    InsertFirst(&First,10);
    InsertFirst(&First,20);

    InsertAtPos(&First, 25, 5);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);
    
    DeleteAtPos(&First, 5);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);
    
    DeleteFirst(&First);
    DeleteFirst(&First);

    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&First);
    Display(First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

  return 0;
}