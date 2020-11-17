
// To find maximum and minimum element in singly linked list. 
#include<stdio.h>
#include<limits.h> 
#include<stdlib.h>   
using namespace std; 
struct Node { 
    int data; 
    struct Node* next; 
}; 
int largestElement(struct Node* head) 
{ 
    int max = INT_MIN; 
    while (head != NULL) { 
        if (max < head->data) 
            max = head->data; 
        head = head->next; 
    } 
    return max; 
} 
int smallestElement(struct Node* head) 
{ 
    int min = INT_MAX; 
    while (head != NULL) { 
        if (min > head->data) 
            min = head->data; 
        head = head->next; 
    } 
    return min; 
} 
void push(struct Node** head, int data) 
{ 
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = (*head); 
    (*head) = newNode; 
} 
void printList(struct Node* head) 
{ 
    while (head != NULL) { 
        printf("%d -> ", head->data); 
        head = head->next; 
    } 
    printf("NULL\n"); 
} 
int main() 
{ 
    struct Node* head = NULL; 
    int i,n; 
     printf("No. of elements to enter:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        push(&head,x);
    }
    printf("Linked list is:\n");
    printList(head); 
    printf("Maximum element in linked list:"); 
    printf("%d ", largestElement(head)); 
    printf("Minimum element in linked list:"); 
    printf("%d",smallestElement(head));
    return 0; 
} 