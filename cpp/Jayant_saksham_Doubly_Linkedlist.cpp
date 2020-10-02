#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *first=NULL;
struct node *last=NULL;
int lengthLL(){
    int count=0;
    struct node*ptr=first;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    return count;
}
void createLL(){
    struct node *temp;
    temp=new node;
    cout<<"Enter data to be inserted : ";
    int data;
    cin>>data;
    temp->data=data;
    temp->next=NULL;
    if(first==NULL){
        temp->previous=NULL;
        first=temp;
        last=temp;
    }
    else{
        temp->previous=last;
        last->next=temp;
        last=temp;
    }
}
void insert(){
    cout<<"Enter element : ";
    int element;
    cin>>element;
    cout<<"Enter index where to be inserted : ";
    int index;
    cin>>index;
    if(index>lengthLL()){
        cout<<"Index out of scope. Try again :-("<<endl;
        return;
    }
    struct node *p=first;
    struct node *temp=new node;
    temp->data=element;
    if(index==0){
        temp->next=first;
        first->previous=temp;
        first=temp;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}

void deleteLL(){
    cout<<"Enter index : ";
    int index;
    cin>>index;
    int len=lengthLL();
    if(index>=len){
        cout<<"Invalid index. Please try again :-("<<endl;
    }
    else if(index==0){
    if(first!=NULL)
        {
        cout<<"\nDeleted Element is "<<first->data;
        first=first->next;
        }
    else
    cout<<"\nNot Able to Delete";
    }
    else if(index==len-1){
        struct node *current=first, *pre=NULL;
        while(current!=last){
            pre=current;
            current=current->next;
        }
        if(current==last){
            cout<<"Deleted elemetn is "<<current->data<<endl;
            pre->next=NULL;
            last=pre;
        }
        else{
            cout<<"Not able to delete"<<endl;
        }
    }
    else{
        struct node *current=first;
        for(int i=0;i<index-1;i++){
            current=current->next;
        }
    }

}
void search(){
    if(first==NULL){
        cout<<"Linked list is empty"<<endl;
    }
    else{
        cout<<"Enter value to be searched : ";
        int value;
        cin>>value;
        bool flag=false;
        struct node *ptr=first;
        int index=0;
        while(ptr!=NULL){
            if(ptr->data==value){
                flag=true;
                cout<<"Element present at "<<index<<"th "<<"index"<<endl;
                break;
            }
            index++;
            ptr=ptr->next;
        }
        if(!flag){
            cout<<"Element "<<value<<" not found in the linked list"<<endl;
        }
    }
}
void display(){
    struct node *ptr=first;
    if(first==NULL){
        cout<<"Linked list is empty"<<endl;
    }
    else{
        struct node *ptr=first;
        while(ptr!=NULL){
            cout<<ptr->data<<"<->";
            ptr=ptr->next;
        }
        cout<<"NULL"<<endl;
    }
}
void menu(){
    cout<<"1 : Create"<<endl;
    cout<<"2: Insert"<<endl;
    cout<<"3: Delete"<<endl;
    cout<<"4: Search"<<endl;
    cout<<"5: Display"<<endl;
    cout<<"Any key to exit"<<endl;
    int choice;
    cin>>choice;
    if(choice==1){
        createLL();
    }
    else if(choice==2){
        insert();
    }
    else if(choice==3){
        deleteLL();
    }
    else if(choice==4){
        search();
    }
    else if(choice==5){
        display();
    }
    else{
        exit(0);
    }
}
int main(){
    while(1){
        menu();
    }    
    return 0;
}