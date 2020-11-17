#include<stdio.h>
#include <malloc/malloc.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *create(struct node *head1);
struct node *display(struct node *head1);
struct node *search(struct node *head1);
struct node *sort(struct node *head1);
struct node *head;
int main()
{
    int b;
    struct node *head;
    char ch ='y';
    head = (struct node *)malloc(sizeof(struct node));
    create(head);
    while(ch=='y'){
         search(head);
        printf("Do you want to search again? y/n ");
        scanf(" %c",&ch);
    }
   
    
    

}
struct node *create (struct node *head1)
{
    int x;
    char ch = 'y';
    printf("Enter info \n");
    scanf("%d",&x);
    head1->info = x;
    printf("do you want to continue? y/n");
    scanf(" %c",&ch);
    if(ch == 'y'|| ch == 'Y')
    {
        head1->next = (struct node *)malloc(sizeof(struct node));
        create(head1->next);
    }
    else
    {
        head1->next = NULL;
    }
}
struct node *display(struct node *head1)
{
    struct node *p;
    for(p = head1 ; p!=NULL;p=p->next)
    printf("%d \t",p->info);
}
struct node *search(struct node *head1)
{
    int val;
    struct node *p;
    p = head1;
    printf("Enter the number you want to search : ");
    scanf("%d",&val);
    for(p=head1;p->info!=val && p->next!=NULL;p=p->next);
    if (p->info==val)
        printf("\n Number is present \n");
    else
        printf("\n Number is not present \n");
}
                  

