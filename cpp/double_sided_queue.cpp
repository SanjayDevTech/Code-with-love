#include <iostream>
using namespace std;
struct node
{
    int val;
    node *next;
};
node *head;
void insert_rear(int d)
{
    node *t = new node;
    t->val = d;
    t->next = head;
    head = t;
}
void insert_front(int d)
{
    node *t = new node;
    t->val = d;
    t->next = NULL;
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        node *c = head;
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = t;
    }
}
void display()
{
    node *t = head;
    while (t != NULL)
    {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}
void delete_rear()
{
    node *temp = head;
    node *prev = head;
    if (temp != NULL)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;
    prev->next = temp->next;

    free(temp);
}

void delete_front()
{
    node *t = head;
    node *cur;
    while (t->next != NULL)
    {
        cur = t;
        t = t->next;
    }
    cur->next = t->next;
    free(t);
}

int main()
{
    insert_rear(1);
    cout << "queue: ";
    display();
    insert_rear(2);
    cout << "queue: ";
    display();
    insert_front(3);
    cout << "queue: ";
    display();
    insert_rear(4);
    cout << "queue: ";
    display();
    insert_front(5);
    cout << "queue: ";
    display();
    insert_front(6);
    cout << "queue: ";
    display();
    insert_front(7);
    cout << "queue: ";
    display();
    delete_rear();
    cout << "queue: ";
    display();
    delete_rear();
    cout << "queue: ";
    display();
    delete_front();
    cout << "queue: ";
    display();
    delete_front();
    cout << "queue: ";
    display();
    return 0;
}

//cout<<"queue: ";