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

void insert_beg(int data) {
	node *newnode = newNode(data);
	size++;
	
	if(head == NULL) {
		head=newnode;
		tail=newnode;
		return;		
	}
	
	newnode->next=head;
	head=newnode;
	
	return;
}

int delete_beg() {
	if(head == NULL) {
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

void display() {
	node *tmp=head;
	if(head == NULL) {
		printf("Stack is Empty.\n");
		return;
	}
	
	printf("Elements in Stack are:\n");
	while(tmp) {
		printf("%d ", tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
	
	return;
}

void push(int item) {
	insert_beg(item);
	return;
}

int pop() {
	return delete_beg();	
}

int peek() {
	if(head == NULL){
		return -1;
	}
	return head->data;
}

void change(int data) {
	head->data=data;
	return;
}

int main() {
	printf("*******MENU*******\n");
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Peek\n");
	printf("4.Change\n");
	printf("5.Display\n");
	printf("6.Exit\n");
	
	while (1) {
		int ch,data;	
		printf("\nEnter Your Choice: ");
		scanf("%d", &ch);
		
		switch (ch) {
			case 1:
				printf("Enter Data: ");
				scanf("%d", &data);
				push(data);
				break;
			case 2:
				data = pop();
				if(data == -1) {
					printf("Stack is Empty.\n");
				}
				else {
					printf("Deleted Element is: %d\n", data);
				}
				break;
			case 3:
				data = peek();
				if(data == -1) {
					printf("Stack is Empty.\n");
				}
				else {
					printf("Element at the peek is: ");
					printf("%d\n", data);
				}
				break;
			case 4:
				printf("Enter Data: ");
				scanf("%d", &data);
				change(data);
				break;
			case 5:
				display();
				break;
			case 6:
				exit (0);
			default:
				printf("Wrong Choice!!\n");
		}
	}
	return 0;
}
