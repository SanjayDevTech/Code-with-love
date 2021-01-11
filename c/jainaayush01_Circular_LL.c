#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;
node *head,*tail;

int size=0;

node *newNode(int data) {
	node *newnode = (node*) malloc (sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;	
}

void insert_end(int data) {
	node *newnode = newNode(data);
	size++;
	
	if(head == NULL){
		head=newnode;
		head->next=newnode;
		tail=newnode;
		return;		
	}
	
	newnode->next=head;
	tail->next=newnode;
	tail=newnode;
	return;
}

void insert_before_pos(int data,int pos){
	pos--;
	if(pos<=0){
		printf("Position Not Found!!");
		return;
	}
	if(pos==size+1||size==0){
		insert_end(data);
	}
	node *newnode=newNode(data);
	pos%=size;
	size++;
	node *tmp=head;
	while(pos>0){
		tmp=tmp->next;
		pos--;
	}
	newnode->next=tmp->next;
	tmp->next=newnode;
	if(newnode->next==head){
		tail=newnode;
	}
	return;
}

int delete_beg(){
	if(head == NULL){
		return -1;
	}
	if(size==1){
		int data=head->data;
		free(head);
		head=NULL;
		tail=NULL;
		size--;
		return data;
	}
	size--;
	node *tmp=head;
	head=head->next;
	tail->next=tmp->next;
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
		pos%=size;
		if(pos == 0 || pos==1) {
			return delete_beg();
		}
		else {
			ptr=head;
			for(i=1; i<pos; i++) {
				temp=ptr;
				ptr=ptr->next ;
			}
			
			size--;
			temp->next =ptr->next ;
			if(temp->next == head) {
				tail=temp;
			}
			data=ptr->data;
			free(ptr);
		}
	}
	return data;
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
	int i=0;
	for(i=0;i<size;++i){
		printf("%d ", tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
	return;
}

int main() {
	int ch,data,pos;
	
	printf("*******MENU*******\n");
	printf("1. Insert at End\n");
	printf("2. Insert Node before specified position\n");
	printf("3. Delete First Node\n");
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
				insert_end(data);
				break;
			case 2:
				printf("Enter Data: ");
				scanf("%d", &data);
				printf("Enter Position(1-Indexed): ");
				scanf("%d", &pos);
				insert_before_pos(data,pos);
				break;
			case 3:
				data = delete_beg();
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
1. Insert at End
2. Insert Node before specified position
3. Delete First Node
4. Delete Node after specified position
5. Display Linked List.
6. Exit

Enter your choice: 1
Enter Data: 1

Enter your choice: 1
Enter Data: 2

Enter your choice: 1
Enter Data: 3

Enter your choice: 2
Enter Data: 3
Enter Position(1-Indexed): 2

Enter your choice: 2
Enter Data: 4
Enter Position(1-Indexed): 3

Enter your choice: 5
Elements in linked list are:
1 2 3 4 3

Enter your choice: 4
Enter the position: 2
Deleted Element is: 3

Enter your choice: 3
Deleted Element is: 1

Enter your choice: 5
Elements in linked list are:
2 4 3

Enter your choice: 6

*/
