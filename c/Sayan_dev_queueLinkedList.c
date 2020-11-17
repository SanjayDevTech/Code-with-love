#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
}*front=NULL,*rear=NULL;

int insert(int x){
    struct node *t=malloc(sizeof(struct node));
    t->info=x;
    t->next=front;
    if(front ==NULL){
        front=t;
        rear=t;

    }
    else{
        rear->next=t;
        rear=t;
    }

}
int delete(){
    int x=-1;
    struct node *t=front;
    if(front==NULL){
        printf("Queue is empty\n");
    }
    else{
        x=t->info;
        front=front->next;
        free(t);
    }
    return x;
}

int display(){
    struct node *t;
    t=front;
    do
    {
        printf("%d\n",t->info);
        t=t->next;
    } while (t!=rear->next);
    
}
int main(){
    insert(12);
    insert(13);
    insert(3);
    insert(7);
    
    display();
    int t=delete();
    delete();
    printf("The deleted number is %d\n",t);
    display();
    
}