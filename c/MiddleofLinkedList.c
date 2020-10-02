//to get the middle element of a linked list

#include <stdio.h> 
#include <stdlib.h> 
using namespace std;
struct node { 
    int data; 
    struct node* next; 
}; 
void printMiddle(struct node* head) 
{ 
    int count = 0; 
    struct node* mid = head; 
  
    while (head != NULL) { 
        if (count%2==1) 
            mid = mid->next; 
        ++count; 
        head = head->next; 
    } 
    if (mid != NULL) 
        printf("The middle element is [%d]\n\n", mid->data); 
} 
void push(struct node** head_ref, int new_data) 
{ 
    struct node* new_node   = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
}   
void printList(struct node* ptr) 
{ 
    while (ptr != NULL) { 
        printf("%d->", ptr->data);
        ptr = ptr->next; 
    } 
    printf("NULL\n");
} 
int main() 
{ 
    struct node* head = NULL; 
    int n;
    printf("No. of elements to enter:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        push(&head,x);
    }
    printList(head); 
    printMiddle(head); 
    return 0; 
}