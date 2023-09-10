#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
    int Data;
    struct Node *next;
    
}NODE,*PNODE,**PPNODE;

int Count(PNODE Head,PNODE Tail)
{
    int iCount = 0;

    if(Head != NULL && Tail != NULL)
    {
       do
       {
          iCount++;
           Head= Head->next;
       }while(Head != Tail->next); 
    
       return iCount;
    }
    else
    {
        return 0;
    }
}

void Display(PNODE Head,PNODE Tail)
{
    printf("Elements of the LL are : \n");
    
    
    if(Head !=NULL && Tail != NULL)
    {
       do
       {
          printf("| %d | -> ",Head->Data);
           Head= Head->next;
       }while(Head != Tail->next); 
    
        printf("\n");
    }
    else
    {
        printf("Linked List is empty\n");
    }
}

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
  PNODE newn = NULL;

  newn = (PNODE)malloc(sizeof(NODE));

  newn->Data= no;
  newn-> next = NULL;

   if((*Head == NULL) && (*Tail == NULL))
   {
     *Head = newn;
     *Tail = newn;

   }
   else
   {
     newn->next = *Head;
     *Head = newn;
   }
   (*Tail)->next =*Head;
}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
    PNODE newn = NULL;

  newn = (PNODE)malloc(sizeof(NODE));

  newn->Data= no;
  newn-> next = NULL;

   if((*Head == NULL) && (*Tail == NULL))
   {
     *Head = newn;
     *Tail = newn;
     
   }
   else
   {
    (*Tail)->next=newn;
    (*Tail)= (*Tail)->next;
   }
    (*Tail)->next =*Head;

}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if((*Head == NULL)&&(*Tail == NULL))
    {
        return;
    }
    else if((*Head == *Tail))
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Tail )-> next );
       ( *Tail ) -> next = *Head;
    }
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
    PNODE temp = *Head;

    if((*Head == NULL)&&(*Tail == NULL))
    {
        return;
    }
    else if((*Head == *Tail))
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
       while(temp->next !=*Tail)
       {
         temp = temp->next;
       } 

       free((*Tail));
       *Tail= temp;
       (*Tail)->next =*Head;
    }
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int iPos)
{
    int iLength = Count(*Head,*Tail);
    PNODE newn = NULL;
    PNODE temp = *Head;

    if((iPos < 1)||( iPos > iLength+1))
    {
        printf("Invalid Input");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,Tail,no);
    }
    else if( iPos == iLength+1)
    {
        InsertLast(Head,Tail,no);
    }
    else
    {
        for(int iCnt = 1; iCnt <iPos-1;iCnt++ )
        {
            temp=temp->next;
        }
        newn = (PNODE)malloc(sizeof(NODE));

        newn->Data = no;
        newn->next = NULL;
        
        newn->next = temp->next;
        temp->next = newn;

    }
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
    int iLength = Count(*Head,*Tail);
    PNODE tempX = NULL;
    PNODE temp = *Head;

    if((iPos < 1)||( iPos > iLength))
    {
        printf("Invalid Input");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if( iPos == iLength+1)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        for(int iCnt = 1; iCnt <iPos-1;iCnt++ )
        {
            temp=temp->next;
        }

        tempX = temp -> next;

        temp->next =temp->next->next;
        free(tempX);
    }
}
int main()
{ 
    PNODE First =NULL;
    PNODE Last = NULL;

    int iRet = 0;

    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,21);
    InsertFirst(&First,&Last,11);

    InsertLast(&First,&Last,101);
    InsertLast(&First,&Last,111);
    InsertLast(&First,&Last,121);

    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&First,&Last,55,4);

    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&First,&Last,4);
    
    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&First,&Last);
    DeleteLast(&First,&Last);
    
    Display(First,Last);
    iRet = Count(First,Last);

    printf("Number of nodes are : %d\n",iRet);
    return 0;
}