#include<stdio.h>
#include <malloc/malloc.h>
#include<stdlib.h>
struct node
{
    int co;
    int exp;
    struct node *next;
};
struct node *create(struct node *head1);
struct node *display(struct node *head1);
struct node *add(struct node *head1, struct node *head2, struct node *start);
struct node *head1 = NULL, *head2 = NULL , *start= NULL ;
int main()
{
    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    start = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter Expression 1 : \n ");
    create(head1);
    printf("\n Expression 1 : \n ");
    display(head1);
    printf("\n Enter Expression 2 : \n");
    create(head2);
    printf("\n Expression 2 : \n ");
    display(head2);
    add(head1, head2, start);
    printf("\n Ans : \n ");
    display(start);
}
   
struct node *create (struct node *head)
{
    char ch = 'y';
    while(ch=='y' || ch=='Y')
    {
        printf("\n Enter coeff : ");
        scanf("%d",&head->co);
        printf("\n Enter power : ");
        scanf("%d",&head->exp);
    head->next=(struct node *)malloc(sizeof(struct node));
    head=head->next;
    head->next=NULL;
    printf("\n Do you wanna continue(y/n)? ");
    scanf(" %c",&ch);
    }
}
struct node *display(struct node *head)
{
    while(head->next!=NULL)
    {
        printf("%dx^%d",head->co,head->exp);
        head=head->next;
        if(head!=NULL)
            printf("  +  ");
        
    }
}

struct node *add(struct node *head1, struct node *head2, struct node *start)
{
    while(head1->next!=NULL && head2->next!=NULL)
     {
         if(head1->exp > head2->exp)
         {
             start->exp = head1->exp;
             start->co = head1->co;
             head1 = head1->next;
         }
         else if(head2->exp > head1->exp)
         {
             start->exp = head2->exp;
             start->co = head2->co;
             head2 = head2->next;
         }
         else 
         {
             start->exp = head1->exp;
             start->co = head1->co + head2->co;
             head1 = head1->next;
             head2 = head2->next;
         }
         start->next = (struct node *)malloc(sizeof(struct node));
         start = start->next;
         start->next = NULL;
     }
    while(head1->next || head2->next)
    {
        if(head1->next)
        {
            start->exp = head1->exp;
            start->co = head1->co;
            head1 = head1->next;
        }
         
        if(head2->next)
        {
            start->exp = head2->exp;
            start->co = head2->co;
            head2 = head2->next;
        }
        start->next = (struct node *)malloc(sizeof(struct node));
         start = start->next;
         start->next = NULL;
    }
}



