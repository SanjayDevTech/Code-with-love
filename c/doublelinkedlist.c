#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist{
    int data;
    struct linkedlist *prev;
    struct linkedlist *next;
}NODE;

NODE *head = NULL;

void create();

void insert();
void insert_begin();
void insert_end();
void insert_anywhere_pos();
void insert_anywhere_ele();

void delete();
void delete_anywhere_pos();
void delete_anywhere_ele();
void delete_end();
void delete_begin();
void display();

int main(){
    int choice;
    
    while(1){
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}

void insert(){
    if(head == NULL){
        create();
    }
    int choice;
    printf("1.insert at begin\n2.insert at end\n3.insert by element\n4.insert by position\n5.exit\n");
    while(1){
        printf("enter your choice : \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert_begin();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_anywhere_ele();
                break;
            case 4:
                insert_anywhere_pos();
                break;
            case 5:
                return;
        }

    }
    return;
}

void create(){
    int ele;
    NODE *p = malloc(sizeof(NODE));
    printf("enter element : ");
    scanf("%d", &ele);
    p -> data = ele;
    p -> prev = NULL;
    p -> next = NULL;
    head = p;
    return;
}

void insert_begin(){
    int ele;
    NODE *q = malloc(sizeof(NODE));
    printf("enter element : ");
    scanf("%d",&ele);
    q -> data = ele;
   // q -> prev = NULL;
    q -> next = head;
    head -> prev = q;
    head = q;
    return;
}

void insert_end(){
  int ele;
  NODE *r = malloc(sizeof(NODE));
  printf("enter element : ");
  scanf("%d",&ele);
  r -> data = ele;
  r -> next = NULL;
  NODE *temp = head;
  while(temp -> next != NULL){
      temp = temp -> next;
  }
  temp -> next = r;
  r -> prev = temp;
  return;
}

void insert_anywhere_pos(){
    int ele, pos, count = 1;
    printf("enter position : \n");
    scanf("%d", &pos);

    NODE *s = malloc(sizeof(NODE));

    printf("enter element : ");
    scanf("%d", &ele);
    
    s -> data = ele;
    NODE *temp = head;
    while(temp  != NULL){
        if(count + 1 == pos){
            break;
        }
        temp = temp -> next;
        count++;
    } 
    s -> prev = temp;
    s -> next = temp -> next;
    temp ->next = s;
    s -> next -> prev = s;
   
    return;
}

void display(){
    NODE *temp = head;
    while(temp != NULL){
        printf("%d \n", (temp -> data));
        temp = temp -> next;
    }
   
    return;
}


void insert_anywhere_ele(){
}

void delete(){
    if(head == NULL){
        printf("no deletion occurs\n");
    }
    else{
        int choice;
        printf("1.delete at begin\n2.delete at end\n3.delete by element\n4.delete by position\n5.exit\n");
        while(1){
            printf("enter your choice : \n");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    delete_begin();
                    break;
                case 2:
                    delete_end();
                    break;
                case 3:
                    delete_anywhere_ele();
                    break;
                case 4:
                    delete_anywhere_pos();
                    break;
                case 5:
                    return;
            }
        }
        return;
    }
}


void delete_begin(){
    printf("deleted element : %d\n", head -> data);
    head -> next -> prev = NULL;
    head = head -> next;
    return;
}

void delete_end(){
    NODE *temp;
    temp = head;
    while(temp -> next  != NULL){
        temp = temp -> next;
    }
    printf("deleted element : %d\n",temp -> data);
    temp -> prev -> next = NULL;
    free(temp);
    return;
}

void delete_anywhere_ele(){
    int d;
    NODE *temp;
    printf("data to delete that node : \n");
    scanf("%d", &d);
    temp = head;
    while(temp -> next != NULL){
        if(temp -> data == d){
            break;
        }
        temp = temp -> next;
    }
    
    temp -> prev -> next = temp -> next;
    temp -> next = temp -> next = NULL;
    
    free(temp);
    return;
}

void delete_anywhere_pos(){
}




