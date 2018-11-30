#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void insert(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if(rear==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=rear->next;
    }
    printf("\nValue inserted\n");
}
int del()
{
    if(front==NULL)
    {
        printf("\nQueue is empty\n");
        return -1;
    }
    int val=front->data;
    if(front==rear)
    {
        front=rear=NULL;
    }
    else
    {
        front=front->next;
    }
    return val;
}
void display()
{
    struct node *curr=front;
    if(front==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
int main()
{
    int val,ch;
    while(1)
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the value to insert:- ");
            scanf("%d",&val);
            insert(val);
            break;
        case 2:
            val=del();
            if(val!=-1)
            {
                printf("The deleted value is:- %d",val);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}
