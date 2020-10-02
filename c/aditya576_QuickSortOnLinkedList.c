//applying quick sort algorithm on a linked list

#include <stdio.h> 
#include <stdlib.h> 
using namespace std; 
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node; 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
void printList(struct Node *node) 
{ 
    while(node!=NULL) 
    { 
         printf("%d ", node->data); 
        node = node->next; 
    } 
    printf("\n"); 
} 
struct Node *getTail(struct Node *cur) 
{ 
    while (cur != NULL && cur->next != NULL) 
        cur = cur->next; 
    return cur; 
} 
struct Node *partition(struct Node *head, struct Node *end, 
                    struct Node **newHead, struct Node **newEnd) 
{ 
    struct Node *pivot = end; 
    struct Node *prev = NULL, *cur = head, *tail = pivot; 
    while (cur != pivot) 
    { 
        if(cur->data<pivot->data) 
        { 
            if ((*newHead) == NULL) 
                (*newHead) = cur; 
  
            prev = cur;  
            cur = cur->next; 
        } 
        else 
        { 
            if(prev) 
                prev->next = cur->next; 
            struct Node *temp = cur->next; 
            cur->next = NULL; 
            tail->next = cur; 
            tail = cur; 
            cur = temp; 
        } 
    } 
    if ((*newHead) == NULL) 
        (*newHead) = pivot; 
    (*newEnd) = tail; 
    return pivot; 
}  
struct Node *quickSortRecur(struct Node *head, struct Node *end) 
{ 
    if (!head || head == end) 
        return head; 
    Node *newHead = NULL, *newEnd = NULL; 
     struct Node *pivot = partition(head, end, &newHead, &newEnd); 
    if (newHead != pivot) 
    { 
        struct Node *temp = newHead; 
        while (temp->next != pivot) 
            temp = temp->next; 
        temp->next = NULL; 
        newHead = quickSortRecur(newHead, temp); 
        temp = getTail(newHead); 
        temp->next = pivot; 
    } 
    pivot->next = quickSortRecur(pivot->next, newEnd); 
    return newHead; 
} 
void quickSort(struct Node **headRef) 
{ 
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef)); 
    return; 
} 
int main() 
{ 
    struct Node *a = NULL; 
    int n;
    printf("No. of elements to enter:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        push(&a,x);
    }
    printf("Linked List before sorting \n"); 
    printList(a);   
    quickSort(&a);  
    printf("Linked List after sorting \n"); 
    printList(a); 
    return 0; 
} 