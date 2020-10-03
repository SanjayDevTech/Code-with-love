#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <malloc.h>

typedef struct node {
    int data;
    struct node * next;
}
node;
node * front = NULL;
node * rear = NULL;
void push();
void pop();
void peep();
void display();

void main() {
    int option;
    clrscr();
    do {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Push");
        printf("\n 2: Pop");
        printf("\n 3: Peep");
        printf("\n 4: Display");
        printf("\n 5: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", & option);
        switch (option) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("\nInvalid Option");

        }
    } while (option != 5);
    getch();
}

void pop() {
    node * ptr;
    if (front == NULL)
        printf("\n Stack empty!!can't delete");
    else {
        ptr = front;
        front = front -> next;
        printf("\n Value poped %d", ptr -> data);
        free(ptr);
    }
}

void peep() {
    if (front == NULL)
        printf("\n Stack empty!!");
    else
        printf("\n Value in front is %d", front -> data);
}

void display() {
    node * ptr;
    ptr = front;
    if (ptr == NULL) {
        printf("\n Stack empty!!");
    } else {
        while (ptr != NULL) {
            printf("\t %d", ptr -> data);
            ptr = ptr -> next;
        }
    }
}

void push() {
    node * ptr;
    node * newnode = (node * ) malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d", & newnode -> data);
    newnode -> next = NULL;
    if (front == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear -> next = newnode;
        rear = newnode;
    }
}
