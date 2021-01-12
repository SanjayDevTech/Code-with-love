#include<stdio.h>
#include<stdlib.h>

int top=-1, *stack, MAX;

void push ();
void pop ();
void display ();
void peek ();
void change ();

void main () {
	printf("Enter Max Size: ");
	scanf("%d",&MAX);

	stack = (int *) malloc (MAX * sizeof(int));
	
	printf("\n*******MENU*******\n");
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Peek\n");
	printf("4.Change\n");
	printf("5.Display\n");
	printf("6.Exit\n");
	
	while (1) {
		int ch;	
		printf("\nEnter Your Choice: ");
		scanf("%d", &ch);
		printf("\n");
		
		switch (ch) {
			case 1: push ();
					break;
			case 2: pop ();
					break;
			case 3: peek ();
					break;
			case 4: change ();
					break;
			case 5: display ();
					break;
			case 6: exit (0);
			default: printf("Wrong Choice!!\n");
		}
	}
}
 
void push () {
	int val;
	
	if (top == MAX-1) {
		printf("Stack is full!!\n");
	} else {
		printf("Enter element to push: ");
		scanf("%d", &val);
		top=top+1;
		stack[top]=val;
	}
}
 
void pop () {
	if (top == -1) {
		printf("Stack is empty!!\n");
	} else {
		printf("Deleted element is %d\n", stack[top]);
		top=top-1;
	}
}

void peek () {
	if (top == -1) {
		printf("Stack is empty!\n");
	} else {
		printf("Top element is %d\n", stack[top]);
	}
}

void display () {
	int i;
	
	if (top == -1) {
		printf("Stack is empty!!\n");
	} else {
		printf("Stack is: ");
		for (i=top; i>=0; --i)
			printf("%d ",stack[i]);
		printf("\n");
	}
}

void change () {
	pop ();
	push ();
}

