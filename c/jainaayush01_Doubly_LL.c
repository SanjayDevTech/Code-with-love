#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
}Node;

Node *head,*tail;
int size=0;

Node *newNode(int data){
	Node *newnode = (Node *) malloc (sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
}


void insert_beg(int data) {
	Node *newnode = newNode(data);
	size++;
	
	if(head == NULL){
		head=newnode;
		tail=newnode;
		return;		
	}
	
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
	
	return;
}

void insert_end(int data) {
	Node *newnode = newNode(data);
	size++;
	
	if(head == NULL){
		head=newnode;
		tail=newnode;
		return;		
	}
	
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
		
	return;
}

int delete_beg(){
	if(head == NULL){
		return -1;
	}
	int data=head->data;
	if(size==1){
		size=0;
		free(head);
		head=NULL;
		tail=NULL;
		return data;
	}
	size--;
	Node *tmp=head;
	head=head->next;
	head->prev=NULL;
	free(tmp);
	
	return data;
}

int delete_end(){
	if(head == NULL){
		return -1;
	}
	int data=tail->data;
	if(size==1){
		size=0;
		free(head);
		head=NULL;
		tail=NULL;
		return data;
	}
	size--;
	Node *tmp=tail;
	tail=tail->prev;
	tail->next=NULL;
	free(tmp);
	
	return data;
}

int delete_pos(int pos) {
	if(pos<=0||pos>size){
		return -1;
	}
	if(pos==1){
		return delete_beg();
	}
	if(pos==size){
		return delete_end();	
	}
	Node *tmp=head;
	size--;
	while(pos!=1){
		tmp=tmp->next;
		pos--;
	}
	int data=tmp->data;
	Node *pre=tmp->prev;
	Node *nxt=tmp->next;
	pre->next=nxt;
	nxt->prev=pre;
	free(tmp);
	return data;
}

int delete_after_pos(int pos){
	return delete_pos(pos+1);
}

void display() {
	Node *tmp=head;
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
	printf("3. Delete Last Node\n");
	printf("4. Delete Node after specified position\n");
	printf("5. Display Linked List.\n");
	printf("6. Exit\n");
	
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
				data = delete_end();
				if(data == -1) {
					printf("List is Empty.\n");
				}
				else {
					printf("Deleted Element is: %d\n", data);
				}
				break;	
			case 4:
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
			case 5:
				display();
				break;
			case 6:
				exit(0);
			default:
				printf("Wrong Choice!!\n");		
		}
	}
	return 0;
}
/*
*******MENU*******
1. Insert at Beginning.
2. Insert at End
3. Delete Last Node
4. Delete Node after specified position
5. Display Linked List.
6. Exit

Enter your choice: 1
Enter Data: 3

Enter your choice: 1
Enter Data: 2

Enter your choice: 1
Enter Data: 1

Enter your choice: 2
Enter Data: 4

Enter your choice: 5
Elements in linked list are:
1 2 3 4

Enter your choice: 3
Deleted Element is: 4

Enter your choice: 5
Elements in linked list are:
1 2 3

Enter your choice: 4
Enter the position: 0
Deleted Element is: 1

Enter your choice: 4
Enter the position: 1
Deleted Element is: 3

Enter your choice: 5
Elements in linked list are:
2

Enter your choice: 2
Enter Data: 6

Enter your choice: 5
Elements in linked list are:
2 6

Enter your choice: 6

*/
