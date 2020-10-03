#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<conio.h>
#include<stdbool.h>
struct node{
	int data;
	struct node* next;
}*start,*newptr;
void create();
void insert_begin();
void insert_middle();
void insert_end();
void delete_front();
void delete_end();
void delete_middle();
void deleteList();
void length();
void searchKey();
void getNode();
void midNode();
void reverseNode();
void delDuplicate();
void display();
int main()
{
	struct node* start = NULL;
	int choice;
	char ans='y';
	while(ans=='y')
	{
		printf("********LINKED LIST**********\n");
		printf("1. Creation of Node\n");
		printf("2. Display\n");
		printf("3. Insertion at the front\n");
		printf("4. Insertion at the Middle\n");
		printf("5. Insertion at the end\n");
		printf("6. Delete at front\n");
		printf("7. Delete at End\n");
		printf("8. Delete at positon\n");
		printf("9. Delete the list\n");
		printf("10. Length of the List\n");
		printf("11. Search a particular node\n");
		printf("12. Find the element using given index value\n");
		printf("13. Print the middle element\n");
		printf("14. Print the List in reverse order\n");
		printf("15. Remove Duplicates\n");
		printf("14. Exit\n");
		printf("Enter the choice::");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: create();
				break;
			case 2: display();
				break;
			case 3: insert_begin();
				break;
			case 4: insert_middle();
				break;
			case 5: insert_end();
				break;
			case 6: delete_front();
				break;
			case 7: delete_end();
				break;
			case 8: delete_middle();
				break;
			case 9: deleteList();
				break;
			case 10: length();
				break;
			case 11: searchKey();
				break;
			case 12: getNode();
				break;
			case 13: midNode();
				break;
			case 14: reverseNode();
				break;
			case 15: delDuplicate();
				break;
			default: exit(1);
		}
		printf("Want to continue?....(y/n):: ");
		scanf(" %c",&ans);
	}
	getch();
}
void create()
{
	struct node  *ptr;
	newptr = (struct node *)malloc(sizeof(struct node));
	if(newptr==NULL)
	{
		printf("Memory is empty");
		exit(0);
	}
	printf("Enter the value for the new info::");
	scanf("%d",&newptr->data);
	newptr->next=NULL;
	if(start==NULL)
	{
		start=newptr;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newptr;
	}
}
void display()
{
	struct node* ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}
void insert_begin()
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory empty");
		exit(0);
	}
	printf("Enter the Value want to insert at the front:: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->next=start;
		start=temp;
	}
}
void insert_middle()
{
	struct node* temp, *ptr;
	int pos,i;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory pass");
		exit(0);
	}
	printf("Enter the position:: ");
	scanf("%d",&pos);
	printf("Enter the value:: ");
	scanf("%d",&temp->data);
	if(pos==0)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		for(i=0, ptr=start; i<pos-1; i++)
		{
			ptr=ptr->next;
			if(ptr==NULL)
			{
				printf("Position not found");
				return;
			}
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
}
void insert_end()
{
	struct node* temp, *ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory empty");
		exit(0);
	}
	printf("Enter the Value:: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void delete_front()
{
	struct node* ptr;
	if(ptr==NULL)
	{
		printf("List empty");
		return;
	}
	else
	{
		ptr=start;
		start=start->next;
		printf("Deleted item is %d",ptr->data);
		free(ptr);
	}
}
void delete_end()
{
	struct node* temp, *ptr;
	if(start==NULL)
	{
		printf("List empty");
		return;
	}
	else if(start->next==NULL)
	{
		ptr=start;
		start=NULL;
		printf("Deleted item is %d",ptr->data);
		free(ptr);
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
		printf("Deleted item is %d\n",ptr->data);
		free(ptr);
	}
}
void delete_middle()
{
	int pos,i;
	struct node* temp, *ptr;
	if(start==NULL)
	{
		printf("List empty");
		return;
	}
	else
	{
		printf("Enter the position:: ");
		scanf("%d",&pos);
		if(pos==0)
		{
			temp=start;
			start=start->next;
			printf("Deleted item is %d",ptr->data);
			free(ptr);
		}
		else
		{
			ptr=start;
			for(i=0; i<pos; i++)
			{
				temp=ptr;
				ptr=ptr->next;
				if(ptr==NULL)
				{
					printf("Position not found");
					return;
				}
				temp->next=ptr->next;
				printf("Deleted item is:: %d\n", ptr->data);
				free(ptr);
			}
		}
	}
}
void deleteList()
{
	struct node* ptr,*temp;
	ptr=start;
	while(ptr!=NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	start=NULL;
	printf("List is deleted\n");
}
void length()
{
	struct node* ptr;
	int count=0;
	ptr=start;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		count++;
	}
	printf("Length of the Node is :: %d\n", count);
}
void searchKey()
{
	struct node* ptr;
	int x, flag=0;
	printf("Enter the Node Value you want to search:: ");
	scanf("%d",&x);
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->data==x)
			flag++;
		ptr=ptr->next;
	}
	if(flag>0)
		printf("Element found\n");
	else
		printf("Element not found\n");
}
void getNode()
{
	struct node* ptr;
	int count=0,i;
	printf("Enter the Node index:: ");
	scanf("%d",&i);
	ptr=start;
	while(ptr!=NULL)
	{
		if(count==i)
			printf("Value is :: %d\n",ptr->data);
		count++;
		ptr=ptr->next;
	}
}
void midNode()
{
	struct node* ptr1;
	struct node* ptr2;
	ptr1=start;
	ptr2=start;
	if(start!=NULL)
	{
		while(ptr1!=NULL && ptr1->next!=NULL)
		{
			ptr1=ptr1->next->next;
			ptr2=ptr2->next;
		}
		printf("Middle element is %d\n",ptr2->data);
	}
}
void reverseNode()
{
	struct node* prev=NULL;
	struct node* current=start;
	struct node* ptr3=NULL;
	while(current!=NULL)
	{
		ptr3=current->next;
		current->next=prev;
		prev=current;
		current=ptr3;
	}
	start=prev;
}
void delDuplicate()
{
	struct node* ptr1, *ptr2, *temp;
	ptr1=start;
	while(ptr1!=NULL && ptr1->next!=NULL)
	{
		ptr2=ptr1;
		while(ptr2->next!=NULL)
		{
			if(ptr1->data==ptr2->next->data)
			{
				temp=ptr2->next;
				ptr2->next=ptr2->next->next;
				free(temp);
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}
