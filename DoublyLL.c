//Doubly Linear LL

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int Data;
  struct Node *next;
  struct Node *prev;
}NODE,*PNODE,**PPNODE;

int Count(PNODE Head)
{
  int iCount = 0;
  

  while(Head != NULL)
  {
    iCount++;
    Head= Head->next;
  }
  return iCount;
}


void Display(PNODE Head)
{
 
  printf("Elements of the LL are : \n");
  while(Head != NULL)
  {
    printf("|%d| ->\t",Head->Data);
    Head= Head->next;
  }

  printf("|NULL|\n");
 
}

void InsertFirst(PPNODE Head ,int no)
{
    PNODE newn = NULL;
    newn= (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->next=NULL;
    newn->prev=NULL;

    if(*Head == NULL)
    {
      *Head =newn;
    }
    else
    {
       ( *Head )->prev = newn;
       newn->next= *Head;
       *Head= newn;
    }
}

void InsertLast(PPNODE Head ,int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn= (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->next=NULL;
    newn->prev=NULL;

    if(*Head == NULL)
    {
      *Head =newn;
    }
    else
    {
       while(temp->next !=NULL)
       {
        temp= temp->next;
       }
       temp->next=newn;
       newn->prev= temp;
    }
}

void DeleteFirst(PPNODE Head )
{

  if(*Head == NULL)
  {
    return;
  }
  else if((*Head) -> next == NULL)
  {
    free(*Head);
    *Head= NULL;
  } 
  else
  {
     *Head= (*Head)->next ;
      free((*Head) -> prev);
    (*Head) -> prev = NULL;
   
  }
}

void DeleteLast(PPNODE Head )
{
 PNODE temp = *Head;

   if(*Head == NULL)
  {
    return;
  }
  else if((*Head) -> next == NULL)
  {
    free(*Head);
    *Head= NULL;
  } 
  else
  {
     while(temp -> next-> next != NULL)
     {
       temp=temp->next;
     }

   free(temp->next);
   temp->next =NULL;


  }
}

void InsertAtPos(PPNODE Head,int no,int iPos )
{
  PNODE newn = NULL;
  PNODE temp=*Head;

  int iLength = 0;
  iLength = Count(*Head);

  int iCnt =0;

  if((iPos <1)||(iPos > iLength+1))
  {
      printf("Invalid Input\n");
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
    newn->prev =NULL;

    for(iCnt =1;iCnt<iPos-1;iCnt++)
    {
        temp=temp->next;
    }
    newn->next=temp->next;
    temp->next->prev = newn;
  
    temp->next= newn;
    newn->prev=temp;
    

   
  }

}

void DeleteAtPos(PPNODE Head,int iPos )
{
   
  PNODE temp=*Head;

  int iLength = 0;
  iLength = Count(*Head);

  int iCnt =0;

  if((iPos <1)||(iPos > iLength))
  {
      printf("Invalid Input\n");
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

    for(iCnt =1;iCnt<iPos-1;iCnt++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    free(temp->next->prev);
    temp->next->prev=temp;

   
  }
}
int main()
{
  PNODE First = NULL;

    int iRet = 0;

    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);        
    InsertFirst(&First,11);

    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    
    InsertLast(&First,111);
    InsertLast(&First,121);

    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    
    InsertAtPos(&First, 55, 4);
    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);

    DeleteAtPos(&First, 4);
    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);

    DeleteFirst(&First);
    DeleteLast(&First);

    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    Display(First);
    
    return 0;
}