#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node{
    int val;
    struct node *next;
}node;


void display(node* list){
    //Print space separated integers from the linked list 
    //list is the pointer pointing to the beginning of the linked list
    node* ptr=list;
    if(ptr==NULL)
    {
    	printf("Empty\n");
    }
    while(ptr!=NULL)
    {
        printf("%d ",ptr->val);
        ptr=ptr->next;
    }
    printf("\n");
}

node* insertAtBeginning(node* list,int val){
    //Write function to insert val at the beginning of the list and return a pointer pointing to beginning of the list
    node *ptr=(node *) malloc(sizeof(node));
    ptr->val=val;
    if(list==NULL)
    {
        list=ptr;
    }
    else 
    {
        ptr->next=list;
        list=ptr;   
    }
    return list;
}

node* insertAtEnd(node* list,int val){
    //Write function to insert val at the end of the list and return a pointer pointing to beginning of the list
    node *n=(node *) malloc(sizeof(node));
    n->val=val;
    if(list==NULL)
    {
        list=n;
    }
    else 
    {
        node *ptr=list;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=n;
    }
    return list;
}

node* insertAtPosition(node* list,int val,int pos){
    //Write function to insert "val" at "pos" in the list and return a pointer pointing to beginning of the list
    node *temp=(node*) malloc(sizeof(node));
    int i,count=0;
    temp->val=val;
    if(pos==0)
    {
        temp->next=list;
        list=temp; 
    }
    i=0;
    node *ptr=list;
    while(i<pos-1)
    {
         ptr=ptr->next;
         i++;
    }
    temp->next =ptr->next ;
    ptr->next=temp;
    return list;
}

node* deleteFromBeginning(node* list,int* flag){
    //Delete from the beginning of the list and return pointer pointing to the beginning of the list
    //If deletion not possible set flag as -1 and return pointer to beginning of list
    if(list==NULL)
    {
        *flag=-1;
    }
    else 
    {
        node *ptr=list;
        list=list->next;
        free(ptr);
        ptr=NULL;
    }   
    return list;
}

node* deleteFromEnd(node* list,int* flag){
    //Delete from the end of the list and return pointer to the beginning of the list
    //If deletion not possible set flag as -1 and return pointer to beginning of list

    node *temp=( node*) malloc(sizeof(node));
    if(list==NULL)
    {
        *flag=-1;
    }
    else if(list->next==NULL)
    {
        free(list);
        list=NULL;
    }
    else 
    {
        node *ptr=list;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
 
        temp->next=NULL;
        free(ptr);
        ptr=NULL;
    }
    return list;
}

node* deleteFromPosition(node* list,int pos,int* flag){
    //Delete from the "pos" of the list and return pointer to the beginning of the list
    //If deletion not possible set flag as -1 and return pointer to beginning of list
    
    int i,notfound=1;
    if(list==NULL)
    {
        *flag=-1;
    }
    else if(pos==0)
    {
        node *ptr=list;
        list=ptr->next;
        free(ptr);
    }
    else
    {
        node *ptr=list;
        node *temp=list;
        for(i=0;i<pos && ptr->next!=NULL;i++)
        {
            temp=ptr;
            ptr=ptr->next;
        } 
        if(ptr->next==NULL)
        {
            *flag=-1;
        } 
        else 
        {
            temp->next=ptr->next;
            free(ptr);  
            ptr=NULL;  
        }  
    }
    
    return list;

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    node* first = NULL;
    int opt,pos=1,val;
    while(opt != 8){
   	 printf("\n1.Display");
   	 printf("\n2.Insert in  the Begining");
   	 printf("\n3.Insert at the End");
   	 printf("\n4.Insert at the specific position");
   	 printf("\n5.Delete from Begining");
   	 printf("\n6.Delete fron End");
   	 printf("\n7.Delete from specific position");
   	 printf("\n8.Exit program\n");
    	scanf("%d",&opt);
        int flag = 0;
        switch(opt){
        case 1:  display(first);
                break;
        case 2: scanf("%d",&val);//printf("insBe %d\n",val);
                first = insertAtBeginning(first,val); 
                break;
        case 3: scanf("%d",&val);//printf("insEn %d\n",val);
                first = insertAtEnd(first,val);
                break;
        case 4: scanf("%d %d",&val,&pos);// printf("insPos %d pos %d\n",val,pos);
                first = insertAtPosition(first,val,pos);
                break;
        case 5: first = deleteFromBeginning(first,&flag);//printf("delBe\n");
                if(flag == -1)
                    printf("Deletion not possible\n");
                break;
        case 6: first = deleteFromEnd(first,&flag); //printf("delEnd\n");
                if(flag == -1)
                    printf("Deletion not possible\n");
                break;
        case 7: scanf("%d",&pos);//printf("delPos %d\n",pos);
                first = deleteFromPosition(first,pos,&flag);
                if(flag == -1)
                    printf("Deletion not possible\n");
                break;
        }
    }
    
    
    return 0;
}
