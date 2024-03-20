/**
 * C program to insert a node in Doubly linked list
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * Basic structure of Node
 */
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;


/*
 * Function used in this program
 */
void createList(int n);
void displayList();
void deleteFromN(int position);

void insertAtN(int data, int position);


int main()
{
    int n, data, choice=1;

    head = NULL;
    last = NULL;

    /*
     * Run forever until user chooses 0
     */
    while(choice != 0)
    {
        /*
         * Menu creation to use the program
         */
        printf("\n");
        printf("DOUBLY LINKED LIST PROGRAM\n");
        printf("\n");
        printf("1. Create List\n");
        printf("2. Insert node - after N\n");
        printf("3. Display list\n");
        printf("4.Delete before the given node\n");
        printf("0. Exit\n");
        printf("\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        /*
         * Choose from different menu operation
         */
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);

                createList(n);
                break;
            
            
            case 2:
                printf("Enter after which node you want to insert : \n");
                scanf("%d", &n);
                printf("Enter data of %d no. node : ", (n+1));
                scanf("%d", &data);

                insertAtN(data, (n+1));
                break;
                
            case 3:
                displayList();
                break;
            case 4:
            	 printf("Enter before which node you want to delete : \n");
                scanf("%d", &n);
            	deleteFromN(n-1);

            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }

        printf("\n\n\n\n\n");
    }

    return 0;
}


/**
 * Creates a doubly linked list of n nodes.
 * @n Number of nodes to be created
 */
void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        /*
         * Create and link the head node
         */
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        /*
         * Create and link rest of the n-1 nodes
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode;          // Make new node as last/previous node
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/**
 * Display content of the list from beginning to end
 */
void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}








/**
 * Inserts a node at any position in the doubly linked list
 * @data Data of the new node to be inserted
 * @position Position where to insert the new node
 */
void insertAtN(int data, int position)
{
    int i;
    struct node * newNode, *temp;

    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

         if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next; // Connect new node with n+1th node
            newNode->prev = temp;          // Connect new node with n-1th node

            if(temp->next != NULL)
            {
                /* Connect n+1th node with new node */
                temp->next->prev = newNode;
            }
            /* Connect n-1th node with new node */
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY AFTER NODE %d\n", (position-1));
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}
/**
 * Delete node from any position in the doubly linked list
 */
void deleteFromN(int position)
{
    struct node *temp;
    int i;

    temp = head;
    for(i=1; i<position && temp!=NULL; i++)
    {
        temp = temp->next;
    }

    if(temp != NULL)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        free(temp); // Delete the n node

        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}
