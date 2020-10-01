#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;
node *head,*tail;

int size=0;

node *newNode(int data) 	{
	node *newnode = (node*) malloc (sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;	
}

node* MergeSortedList(node* l1, node* l2) {
	node *tmp = newNode(-1);
	
	node *h=tmp;
	
	while (l1 && l2) {
		if (l1->data <= l2->data) {
			tmp->next=l1;
			l1=l1->next;
		}
		else {
			tmp->next=l2;
			l2=l2->next;
		}
		tmp=tmp->next;
	}
	
	while(l1) {
		tmp->next=l1;
		tmp=tmp->next;
		l1=l1->next;
	}
	
	while(l2) {
		tmp->next=l2;
		tmp=tmp->next;
		l2=l2->next;
	}
	return h->next;
}

node* MergeSort(node* h) {
	if(!h)
		return h;
	if(!h->next)
		return h;
	
	node *slow=h, *fast=h;
	while(fast && fast->next && fast->next->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	
	fast=slow->next;
	slow->next=NULL;
	
	slow=MergeSort(h);
	fast=MergeSort(fast);
	
	h=MergeSortedList(slow,fast);
	return h;
}

node *sortList(node* h) {
	if(!h || !h->next)
		return h;
	
	h=MergeSort(h);
	return h;
}

void insert_beg(int data) {
	node *newnode = newNode(data);
	size++;
	
	if(head == NULL){
		head=newnode;
		tail=newnode;
		return;		
	}
	
	newnode->next=head;
	head=newnode;
	
	return;
}

void insert_end(int data) {
	node *newnode = newNode(data);
	size++;
	
	if(tail == NULL){
		head=newnode;
		tail=newnode;
		return;
	}
	
	tail->next=newnode;
	tail=newnode;
	
	return;
}

void insert_asc(int data) {
	node *newnode=newNode(data);
	size++;
	
	if(head == NULL) {
		head=newnode;
		tail=newnode;
		return;
	}
	
	newnode->next=head;
	head=newnode;
	
	head = sortList(head);
	
	node *tmp=head;
	while(tmp && tmp->next) {
		tmp=tmp->next;
	}
	tail=tmp;
	
	return;
}

int delete_beg(){
	if(head == NULL){
		return -1;
	}
	
	size--;
	node *tmp=head;
	head=head->next;
	if(head == NULL) {
		tail=NULL;
	}
	int data=tmp->data;
	free(tmp);
	
	return data;
}

int delete_pos(int pos) {
	node *temp, *ptr;
	int i,data;
	if(head == NULL || pos == 0) {
		return -1;
	}
	else {
		if(pos == 1) {
			ptr=head;
			head=head->next ;
			size--;
			if(head == NULL) {
				tail=NULL;
			}
			data=ptr->data;
			free(ptr);
		}
		else {
			ptr=head;
			for(i=1; i<pos; i++) {
				temp=ptr;
				ptr=ptr->next ;
				if(ptr == NULL) {
					return -1;
				}
			}
			
			size--;
			temp->next =ptr->next ;
			if(temp->next == NULL) {
				tail=temp;
			}
			data=ptr->data;
			free(ptr);
		}
	}
	return data;
}

int delete_before_pos(int pos) {
	return delete_pos(pos-1);
}

int delete_after_pos(int pos) {
	return delete_pos(pos+1);
}

void display() {
	node *tmp=head;
	if(head == NULL){
		printf("List is Empty.\n");
		return;
	}
	
	printf("Elements in linked list are:\n");
	while(tmp) {
		printf("%d ", tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
	
	return;
}

int main() {
	int ch,data,pos;
	
	printf("*******MENU*******\n");
	printf("1. Insert at Beginning.\n");
	printf("2. Insert at End\n");
	printf("3. Insert such that linked list is in ");
	printf("ascending order.\n");
	printf("4. Delete First Node\n");
	printf("5. Delete Node before specified position\n");
	printf("6. Delete Node after specified position\n");
	printf("7. Display Linked List.\n");
	printf("8. Exit\n");
	
	while(1) {
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Enter Data: ");
				scanf("%d", &data);
				insert_beg(data);
				break;
			case 2:
				printf("Enter Data: ");
				scanf("%d", &data);
				insert_end(data);
				break;
			case 3:
				printf("Enter Data: ");
				scanf("%d", &data);
				insert_asc(data);
				break;
			case 4:
				data = delete_beg();
				if(data == -1) {
					printf("List is Empty.\n");
				}
				else {
					printf("Deleted Element is: %d\n", data);
				}
				break;
			case 5:
				printf("Enter the position: ");
				scanf("%d", &pos);
				data = delete_before_pos(pos);
				if(data == -1) {
					printf("Node before that position ");
					printf("not found.\n");
				}
				else {
					printf("Deleted Element is: %d\n", data);
				}
				break;	
			case 6:
				printf("Enter the position: ");
				scanf("%d", &pos);
				data = delete_after_pos(pos);
				if(data == -1) {
					printf("Node after that position ");
					printf("not found.\n");
				}
				else {
					printf("Deleted Element is: %d\n", data);
				}
				break;
			case 7:
				display();
				break;
			case 8:
				exit(0);
			default:
				printf("Wrong Choice!!\n");		
		}
	}
	return 0;
}
