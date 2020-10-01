#include<bits/stdc++.h>
using namespace std;

class node{
public :
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }    
};

void insertAtHead(node* &head, int data){
    node* n = new node(data);
    if(head == NULL){
        head = n;
        head->next = head;
        return;
    }
    n->next = head;
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    head = n;
    temp->next = head;
}

void insertAtTail(node* &head, int data){
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    node* n = new node(data);
    n->next = head;
    temp->next = n;
}

void insertion(node* &head){
    int ch, data;
    cout<<"Enter 1 to insert at Head "<<endl;
    cout<<"Enter 2 to insert at Tail "<<endl;
    cout<<"Enter choice : ";
    cin>>ch;
    cout<<"Enter the data : ";
    cin>>data;
    switch(ch){
        case 1 : insertAtHead(head,data);
                break;
        case 2 : insertAtTail(head,data);
                break;
        default : cout<<"Wrong Choice"<<endl;
    }
}

void deleteAtHead(node* &head){
    node* toDel = head;
    node* temp = head;
    if(temp->next == head){
        head == NULL;
        delete temp;
        return;
    }
    while(temp->next!=head){
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    delete toDel;
}

void deleteAtTail(node* &head){
    node* temp = head;
    while(temp->next->next!=head){
        temp = temp->next;
    }
    node* toDel = temp->next;
    temp->next = head;
    delete toDel;
}

void deletion(node* &head){
    int ch;
    cout<<"Enter 1 to delete at Head "<<endl;
    cout<<"Enter 2 to delete at Tail "<<endl;
    cout<<"Enter choice : ";
    cin>>ch;
    switch(ch){
        case 1 : deleteAtHead(head);
                break;
        case 2 : deleteAtTail(head);
                break;
        default : cout<<"Wrong Choice"<<endl;
    }
}

void display(node* head){
    node* temp = head;
    cout<<"Link List -> ";
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

void search(node* head){
    int data;
    cout<<"Enter the data to find : ";
    cin>>data;
    if(head->data == data){
        cout<<"Element Found at position 1"<<endl;
        return;
    }
    node* temp = head->next;
    int pos = 2;
    while(temp!=head){
        if(temp->data == data){
            cout<<"Element Found at position "<<pos<<endl;
            return;
        }
        pos++;
        temp = temp->next;
    }
    cout<<"Element not found"<<endl;
}

int main(){
    node* head = NULL;
    int ch;
    cout<<"Enter 1 for insertion"<<endl;
    cout<<"Enter 2 for deletion"<<endl;
    cout<<"Enter 3 for searching"<<endl;
    cout<<"Enter your choice : ";
    cin>>ch;
    while(ch >= 1 and ch <= 3){
        switch(ch){
            case 1 : insertion(head);
                    break;
            case 2 : deletion(head);
                    break;
            case 3 : search(head);
        }
        display(head);
        cout<<"Enter your choice : ";
        cin>>ch;
    }
}