#include<stdio.h>
#include<stdlib.h>

int *queue;
int rear=-1;
int front=-1;
int MAX;

void enqueue(int item);
int dequeue();
int display_front();
void display();
int isEmpty();

int main() {
	int choice,item;
	printf("Enter Maximum Size of the Queue: ");
	scanf("%d", &MAX);
	
	queue = (int *) malloc (MAX * sizeof(int));
	
	printf("\n******MENU******\n");
	printf("1. Enqueue.\n");
	printf("2. Dequeue.\n");
	printf("3. Display Front.\n");
	printf("4. Display Queue.\n");
	printf("5. Quit.\n\n");
	
	while(1) {    
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Enter the element: ");
				scanf("%d", &item);
				enqueue(item);
				printf("\n");
				break;
			case 2:
				item=dequeue();
				if(item != -1)
					printf("Deleted element is: %d\n\n", item);
				break;
			case 3:
				item=display_front();
				if(item != -1){
					printf("Element at the front is: ");
					printf("%d\n\n", display_front());
				}
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


void enqueue(int item) {
    if( rear == MAX-1 ){
        printf("Queue Overflow\n");
        return;
    }
    if( front == -1 )
        front=0;
    rear=rear+1;
    queue[rear]=item ;
}


int dequeue() {
	int item;
	if(isEmpty()){
		printf("Queue Underflow\n");
		return;
	}
	item=queue[front];
	front=front+1;
	if(front == MAX){
		front=-1;
		rear=-1;	
	}
	return item;
}


int display_front() {
	if(isEmpty()){
		printf("Queue Underflow\n\n");
		return -1;
	}
	return queue[front];
}
	

int isEmpty() {
    if(front == -1 || front == rear+1)
        return 1;
    else
        return 0;
}


void display(){
    int i;
    if ( isEmpty() ){
        printf("Queue is empty\n\n");
        return;
    }
    printf("Elements in Queue are: ");
    for(i=front; i<=rear; i++)
        printf("%d ", queue[i]);
    printf("\n\n");
}
