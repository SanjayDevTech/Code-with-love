#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
typedef struct node {
    int data;
    struct node *link;
}NODE;
NODE *head = NULL;
void create();
void insert();
void insert_begin();
void insert_end();
void insert_middle();
void insert_middle_position();
void insert_middle_data();
void delete();
void delete_begin();
void delete_end();
void delete_middle();
void delete_middle_position();
void delete_middle_data();
void display();
void insert(){
    if (head == NULL){
        create();
    }else {
        int option;
        printf("Enter your option :1.Insert at begin 2.Insert at middle 3.Insert at end\n");
        scanf("%d",&option);
        switch(option){
            case 1:insert_begin();
            break;
            case 2:insert_middle();
            break;
            case 3:insert_end();
            break;
            
        }
    }
}
void create(){
    NODE *p = malloc(sizeof(NODE));
    int element;
    printf("Enter the element:");
    scanf("%d",&element);
    p->data = element;
    p->link = NULL;
    head = p;
    
}
void insert_begin(){
    NODE *p = malloc(sizeof(NODE));
    int element;
    printf("Enter the element:");
    scanf("%d",&element);
    p->link = head;
    head = p;
    p->data = element;
}
void insert_end(){
    NODE *temp = head;
    NODE *p = malloc(sizeof(NODE));
    int element;

    printf("Enter the element:");
    scanf("%d",&element);
    while(temp->link != NULL){
        temp = temp->link;
    }
   
    p->data = element;
    p->link = NULL;
    temp->link = p;
    
}
void insert_middle(){
    int option;
    printf("Enter your option :1.Inser after a given position 2.Insert after a given data\n");
    scanf("%d",&option);
    switch(option) {
        case 1:insert_middle_position();
        break;
        case 2:insert_middle_data();
        break;
    }
}
void insert_middle_position(){
    NODE *temp = head;
    NODE *p = malloc(sizeof(NODE));
    int count = 1,pos,element;
    printf("Enter the position after which the node to be inserted:");
    scanf("%d",&pos);
	printf("Enter the element to be inserted:");
    scanf("%d",&element);
    if(pos == 1){
		p->data = element;
		p->link = temp->link;
		temp->link = p;
	}else if(pos > 1){
        while(temp->link != NULL){
            temp = temp->link;
            count++;
            if(count == pos){
                p->data = element;
                p->link = temp->link;
                temp->link = p;
                break;
            }
        }
    }
}
void insert_middle_data(){
    int element,e1;
    NODE *temp=head;
    NODE *p = malloc(sizeof(NODE));
    printf("Enter the element after which the data need to be inserted:");
    scanf("%d",&e1);
    printf("Enter the element to be inserted:");
    scanf("%d",&element);
    if(temp->data == e1){
		p->data = element;
		p->link = temp->link;
		temp->link = p;
		
	}else {
		while(temp->link != NULL){
			temp = temp->link;
            if(temp->data == e1){
                p->data = element;
                p->link = temp->link;
                temp->link = p;
                break;
			}
        }
    }
}
void delete_middle_position(){
    NODE *ptr,*temp = head;
    int pos,count=1;
    printf("Enter the position at which node to be deleted:");
    scanf("%d",&pos);
	if(pos == 1){
		delete_begin();
	}else if(pos > 1){
		
        while(temp->link != NULL){
            ptr = temp;
            temp = temp->link;
		    count++;
            if(count == pos){
                ptr->link = temp->link;
                free(temp);
                break;
			}
        }
    }
}
void delete_middle_data(){
    NODE *temp =head,*ptr;
    int element;
    printf("Enter the element to be deleted:");
    scanf("%d",&element);
    while(temp->link != NULL){
        ptr = temp;
        temp = temp->link;
        if(temp->data == element){
            ptr->link = temp->link;
            free(temp);
            break;
        }
    }
}
void display(){
	NODE *temp;
	temp = head;
	
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}
void delete(){
    int option;
    printf("Enter your option :1.Delete at begin 2.Delete at middle 3.Delete at end \n");
    scanf("%d",&option);
    switch(option){
        case 1:delete_begin();
        break;
        case 2:delete_middle();
        break;
        case 3:delete_end();
        break;
        
    }
}
void delete_begin(){
    NODE *temp = head;
    head = head->link;
    free(temp);
}
void delete_end(){
    NODE *ptr ,*temp = head;
    while(temp->link != NULL){
      ptr = temp;
        temp = temp->link;
    }
    ptr->link = NULL;
    free(temp);
}
void delete_middle(){
    int option;
    printf("Enter your option :1.Delete at a given position 2.Delete a given data\n");
    scanf("%d",&option);
    switch(option) {
        case 1:delete_middle_position();
        break;
        case 2:delete_middle_data();
        break;
    }
}
int main(){
    int choice;
    while(1){
        printf("Enter your choice :1.create 2.insert 3.delete 4.display 5.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:create();
            break;
            case 2:insert();
            break;
            case 3:delete();
            break;
            case 4:display();
            break;
            case 5 :exit(0);
            
        }
    }
    return 0;
}
