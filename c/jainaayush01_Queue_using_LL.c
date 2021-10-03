#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;
node *head,*tail;

int size=0;

node *newNode(int data){
	node *newnode = (node*) malloc (sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;	
}

void insert_end(int data){
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

void display() {
	node *tmp=head;
	if(head == NULL){
		printf("Queue is Empty.\n");
		return;
	}
	
	printf("Elements in Queue are:\n");
	while(tmp) {
		printf("%d ", tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
	
	return;
}

void enqueue(int item){
	insert_end(item);
	return;
}

int dequeue(){
	return delete_beg();	
}

int front(){
	if(head==NULL){
		return -1;
	}
	return head->data;
}


int main(){
	printf("******MENU******\n");
	printf("1. Enqueue.\n");
	printf("2. Dequeue.\n");
	printf("3. Display Front.\n");
	printf("4. Display Queue.\n");
	printf("5. Quit.\n");
	
	int data,choice;
	while(1) {    
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Enter the element: ");
				scanf("%d", &data);
				enqueue(data);
				break;
			case 2:
				data = dequeue();
				if(data == -1) {
					printf("Queue is Empty.\n");
				}
				else {
					printf("Deleted Element is: ");
					printf("%d\n", data);
				}
				break;
			case 3:
				data = front();
				if(data == -1) {
					printf("Queue is Empty.\n");
				}
				else {
					printf("Element at the front is: ");
					printf("%d\n", data);
				}
				break;
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}
/*
******MENU******
1. Enqueue.
2. Dequeue.
3. Display Front.
4. Display Queue.
5. Quit.

Enter your choice: 1
Enter the element: 1

Enter your choice: 1
Enter the element: 2

Enter your choice: 1
Enter the element: 3

Enter your choice: 2
Deleted Element is: 1

Enter your choice: 1
Enter the element: 5

Enter your choice: 3
Element at the front is: 2

Enter your choice: 4
Elements in Queue are:
2 3 5

Enter your choice: 2
Deleted Element is: 2

Enter your choice: 2
Deleted Element is: 3

Enter your choice: 2
Deleted Element is: 5

Enter your choice: 2
Queue is Empty.

Enter your choice: 4
Queue is Empty.

Enter your choice: 3
Queue is Empty.

Enter your choice: 5

*/
