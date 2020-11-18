#include <stdio.h>
#include <stdlib.h>


typedef struct Stack
{
    int info;
    struct Stack *next;
}Stack;

void push(Stack * s, int data)
{
    /*
    *   Return value : void
    *   Input        : Pointer to the stack "s",Integer to be inserted "data"
    */
    Stack *temp=malloc(sizeof(Stack)); 
    temp->info=data;
    temp->next=NULL;
    
    if(s->next!=NULL) 
    {
        temp->next=s->next;
    }
    s->next=temp;
}

void pop(Stack * s)
{
    /*
    *   Return value : void
    *   Input        : Pointer to the stack "s"
    */
    if(s->next==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        Stack *temp;
        temp=s->next;
        s->next=temp->next;
        free(temp);  
        temp->next=NULL; 
    }    
}

void display(Stack * s)
{
    /*
    *   Return value : void 
    *   Input        : Pointer to the stack "s"
    */
    if(s->next==NULL)
    {
        printf("Empty\n");
        return;
    }
    else
    {
        Stack * temp;
        temp=s->next;
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Stack * s = (Stack *)malloc(sizeof(Stack));
    while(1)
    {
        int choice;
	printf("\n\n1.Push\n");
	printf("2.Pop\n");
	printf("3.Display\n");
	printf("4.Exit Program\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            {
                int data;
		printf("Enter the data to be pushed\n");
                scanf("%d",&data);
                push(s,data);
            }
            break;

            case 2:
            {
                pop(s);
            }
            break;

            case 3:
            {
                display(s);
            }
            break;

            case 4:
            {
                return 0;
            }
            break;
        }
    }
    return 0;
}
