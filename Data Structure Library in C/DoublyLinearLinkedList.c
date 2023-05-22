#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))    // Empty LL
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else    // LL contains atleast one node
    {
        newn->next = *First;
        *First = newn;
        (*Last)->next = *First;
    }
}

void InsertLast(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))    // Empty LL
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else    // LL contains atleast one node
    {
        (*Last) -> next = newn;
        *Last = newn;
        (*Last)->next = *First;
    }
}

void Display(PNODE First, PNODE Last)
{
    printf("Elements of Linked list are : \n");

    do
    {
        printf("| %d |-> ",First->data);
        First = First -> next;
    }while(First != Last->next);
    printf("\n");
}

int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;
    do
    {
        iCnt++;
        First = First -> next;
    }while(First != Last->next);
    return iCnt;
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
    PNODE temp = *First;

    if((*First == NULL) && (*Last == NULL)) // Empty LL
    {
        return;
    }
    else if(*First == *Last)    // Single node in LL
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        *First = (*First)->next;
        free(temp);
        (*Last) ->next = *First;
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    PNODE temp = *First;

    if((*First == NULL) && (*Last == NULL)) // Empty LL
    {
        return;
    }
    else if(*First == *Last)    // Single node in LL
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        while(temp->next != (*Last))
        {
            temp = temp -> next;
        }

        free(temp->next);   // free(*Last);
        *Last = temp;
        (*Last) ->next = *First;
    }
}

void InsertAtPos(PPNODE First, PPNODE Last, int no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count(*First, *Last);
    PNODE newn = NULL;
    PNODE temp = *First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First,Last,no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(First,Last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE First, PPNODE Last, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count(*First, *Last);
    PNODE temp1 = *First;
    PNODE temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First,Last);
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast(First,Last);
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        free(temp2);
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int iChoice = 0, iPos = 0, iRet = 0, iNo = 0;

    printf("Welcome to the data structre application written by Marvellous Infosystems\n");

    while(1)
    {
        printf("------------------------------------------\n");

        printf("Please select the desired option : \n");
        printf("1 : Insert new node at first position\n");
        printf("2 : Insert new node at last position\n");
        printf("3 : Insert new node at given position\n");
        printf("4 : Delete node from first position\n");
        printf("5 : Delete node from last position\n");
        printf("6 : Delete node from given position\n");
        printf("7 : Display the contents of Linked List\n");
        printf("8 : Count number of nodes from Linked List\n");

        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter the data that you want to insert : \n");
                scanf("%d",&iNo);

                InsertFirst(&Head, &Tail, iNo);
                break;

            case 2:
                printf("Enter the data that you want to insert : \n");
                scanf("%d",&iNo);

                InsertLast(&Head, &Tail, iNo);
                break;

            case 3:
                printf("Enter the data that you want to insert : \n");
                scanf("%d",&iNo);

                printf("Enter the position : \n");
                scanf("%d",&iPos);

                InsertAtPos(&Head, &Tail, iNo, iPos);
                break;

            case 4:
                DeleteFirst(&Head, &Tail);
                break;

            case 5:
                DeleteLast(&Head, &Tail);
                break;

            case 6:
                printf("Enter the position : \n");
                scanf("%d",&iPos);

                DeleteAtPos(&Head, &Tail, iPos);
                break;

            case 7:
                Display(Head, Tail);
                break;

            case 8:
                iRet = Count(Head, Tail);
                printf("Number of elements are : %d\n",iRet);
                break;

            case 9:
                printf("Thank you for using the application\n");
                return 0;

            default:
                printf("Invalid option\n");
                break;
        }
        printf("------------------------------------------\n");
    }

    return 0;
}