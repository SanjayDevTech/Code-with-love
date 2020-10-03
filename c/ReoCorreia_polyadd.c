#include<stdio.h>
#include<conio.h>
typedef struct node
{
	int coeff;
	int pow;
	struct node *next;
}node;

node* start1=NULL;
node* start2=NULL;
node* start3=NULL;

node *create_poly(node *);
void display_poly(node *);
node *add_poly(node*, node *);
node *add_node(node*, int ,int);

int main()
{
	clrscr();
	printf("\nEnter the first polynomial\n");
	start1=create_poly(start1);
	printf("\nEnter the second polynomial\n");
	start2=create_poly(start2);
	printf("\nThe first polynomial is:");
	display_poly(start1);
	printf("\nThe second polynomial is:");
	display_poly(start2);
	printf("\nThe addition of the polynomials is :");
	start3=add_poly(start1,start2);
	display_poly(start3);
	getch();

}

node *create_poly(node* start)
{
	node *newnode,*ptr;
	int p,c;
	int choice=0;
	printf("Enter each term in decreasing order of power\n");
	do
	{
		printf("Enter term details:");
		printf("\nEnter Coefficient:"); scanf("%d",&c);
		printf("Enter Power:");scanf("%d",&p);
		newnode=(node *)malloc(sizeof (struct node));
		newnode->coeff=c;
		newnode->pow=p;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;

			}
			ptr->next=newnode;
		}

		printf("Do you want to add another term? (1-yes,0-no):");
		scanf("%d",&choice);

	}while(choice!=0);
	return start;
}

void display_poly(struct node *start)
{
    node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->coeff<0)
			printf("-%d x^%d  ",abs(ptr->coeff),ptr->pow);
		else
			printf("+ %d x^%d  ",ptr->coeff,ptr->pow);
		ptr=ptr->next;
	}
}

 node* add_poly( node* start1,  node* start2)
{
	node *ptr1, *ptr2;
	int sum_num,c;
	ptr1=start1; ptr2=start2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->pow==ptr2->pow)
		{
			sum_num=ptr1->coeff+ptr2->coeff;
			start3=add_node(start3,sum_num,ptr1->pow);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->pow>ptr2->pow)
		{
			start3=add_node(start3,ptr1->coeff,ptr1->pow);
			ptr1=ptr1->next;
		}
		else
		{
			start3=add_node(start3,ptr2->coeff,ptr2->pow);
			ptr2=ptr2->next;
		}

	}

	if (ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			start3=add_node(start3,ptr2->coeff,ptr2->pow);
			ptr2=ptr2->next;
		}

	}

	if (ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			start3=add_node(start3,ptr1->coeff,ptr1->pow);
			ptr1=ptr1->next;
		}

	}

	return start3;
}


struct node* add_node(struct node *start,int c,int p)
{
	struct node *ptr, *newnode;
	newnode= (node *)malloc(sizeof (struct node));
	newnode->coeff=c;
	newnode->pow=p;
	newnode->next=NULL;

	if(start==NULL)
	{

		start=newnode;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}

	return start;
}
