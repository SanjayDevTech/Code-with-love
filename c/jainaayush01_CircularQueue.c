#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int queue[MAX];
int rear = -1, front = -1, size = 0;

void enqueue(int item);
int dequeue();
int display_front();
void display();
int isEmpty();

int main() {
	int choice,item;

	
	printf("******MENU******\n");
	printf("1.Enqueue.\n");
	printf("2.Dequeue.\n");
	printf("3.Display Front.\n");
	printf("4.Display Queue.\n");
	printf("5.Quit.\n\n");
	
	while(1) {
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Enter the element: ");
				scanf("%d",&item);
				enqueue(item);
				printf("\n");
				break;
			case 2:
				item=dequeue();
				if(item!=-1)
					printf("Deleted element is: %d\n\n",item);
				break;
			case 3:
				item=display_front();
				if(item!=-1)
					printf("Element at the front is: " );
					printf("%d\n\n",display_front());
				break;
			case 4:
				display();
				break;
			case 5:
				exit(1);
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}


void enqueue(int item) {
	if (size == MAX) {	
		printf("Queue Overflow\n");
		return;
	}
    if (front == -1)
        front=0;
    rear=(rear+1)%MAX;
    queue[rear]=item;
    size++;
    return;
}


int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue Underflow\n\n");
        return -1;
    }
    item=queue[front];
    front=(front+1)%MAX;
    size--;
    return item;
}	


int display_front() {
    if (isEmpty()) {
        printf("Queue Underflow\n\n");
        return -1;
    }
    return queue[front];
}
	

int isEmpty() {
    if (size==0)
        return 1;
    else
        return 0;
}


void display() {
	int i;
	if (isEmpty()){
		printf("Queue is empty\n\n");
		return;
	}
	
	printf("Elements in Queue are: ");
	if(front <= rear) {	
		for(i=front; i <= rear; ++i)
			printf("%d ",queue[i]);
	}
	else {
		for(i=front; i < MAX; ++i)
			printf("%d ",queue[i]);
		for(i=0; i<=rear; ++i)
			printf("%d ",queue[i]);
	}
	printf("\n\n");
	return;
}
