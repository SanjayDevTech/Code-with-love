/* Stack implementation using Array*/
#include<stdlib.h>
#include<stdio.h>
#define size 5
int stack[size];
int top=-1;
void push(int val)
{
	if(top==size-1)
		printf("\nStack Full!!\n");
	else
	{
		top++;
		stack[top]=val;
	}
}

void pop()
{

	if(top==-1)
		printf("\nStack Empty!!\n");
	else
	{
		printf("\nElement removed=%d",stack[top]);
		top--;
	}
}
void peep()
{
	int val;
	if(top==-1)
		printf("\nStack Empty!!\n");
	else
	{
		printf("Element at top=%d",stack[top]);

	}
}
void display()
{	int i;
	if(top==-1)
		printf("\nStack Empty!!\n");
	else
	{	printf("\nStack elements:\n");
		for(i=top;i>=0;i--)
				printf("%d\n",stack[i]);

	}
}

int main()
{
	int choice;int val;

	while(1)
	{
	printf("\n1. Push  2. Pop  3. Peep  4. Display  5. Exit\n Enter your  choice:");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
				printf("Enter value: ");
				scanf("%d",&val);
				push(val);break;
		case 2: pop(); break;
		case 3: peep(); break;
		case 4: display(); break;
		case 5: exit(0);
		default: printf("Enter valid choice!!\n");

	}
	}

}
/*

1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:2
Stack Empty!!

1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:1
Enter val:34

1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:1
Enter val:67

1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:1
Enter val:78

1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:4

Stack elements:
78
67
34
1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:3
Element at top=78
1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:2
Element removed=78
1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:
2
Element removed=67
1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:2
Element removed=34
1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:2
Stack Empty!!

1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:4
Stack Empty!!

1. Push  2. Pop  3. Peep  4. Display  5. Exit
 Enter your  choice:5

Press Enter to return to Quincy...
*/
