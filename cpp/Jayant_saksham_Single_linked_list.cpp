#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
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

void display(){
    struct node *ptr=first;
    if(first==NULL){
        cout<<"Linked list is empty !"<<endl;
    }
    else{
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
        cout<<"NULL"<<endl;
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
void createLL(){
    struct node *temp;
    temp=new node;
    int n;
    cout<<"Enter an element data : ";
    cin>>n;
    temp->data=n;
    temp->next=NULL;
    if(first==NULL){
        first=temp;
        last=temp;
    }
    else{
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
    if(first==NULL){
        cout<<"Linked list is empty"<<endl;
    }
    else{
        cout<<"Enter index to deletion : ";
        int index;
        cin>>index;
        if(index>=lengthLL()){
            cout<<"Index out of scope. PLease try again :-("<<endl;
        }
        else if(index==0){
            struct node *p=first;
            p=first;
            first=first->next;
            cout<<"Deleted element is "<<p->data<<endl;
            delete p;
        }
        else{
            struct node *p=first, *q=NULL;
            for(int i=0;i<index;i++){
                q=p;
                p=p->next;
            }
            q->next=p->next;
            p->next=NULL;
            cout<<"Deleted element is "<<p->data<<endl;
            delete p;
        }
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