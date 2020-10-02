#include<bits/stdc++.h>
#define s 20

using namespace std;
char Stack[s],top;
void push(char);
char pop();
bool isEmpty();
char Top();
void display(char Stack[],int top);

int main()
{
    char str[20],t;
    int flag=1;
    cout<<"ENTER THE PARENTHESIS EXPRESSION: ";
    cin>>str;

    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]=='[')||(str[i]=='{')||(str[i]=='('))
            push(str[i]);
        else if(((Top()=='(')&&(str[i]==')'))||((Top()=='{')&&(str[i]=='}'))||((Top()=='[')&&(str[i]==']')))
            t=pop();
        else
        {
            flag=0;
            break;
        }
    }

    if(flag==0)
        cout<<"FALSE";
    else
        cout<<"TRUE";


    return 0;
}

void push(char x)
{
    if(top+1==s)
    {
        cout<<"OVERFLOW!!";
    }
    else
    {
        Stack[++top]= x;
        //cout<<"ELEMENT PUSHED SUCCESSFULLY!!!!";
    }
}

char pop()
{
    if(isEmpty())
    {
        cout<<"UNDERFLOW!!!!";
        return '!';
    }
    else
    {
        char x = Top();
        top--;
        return x;
    }
}

bool isEmpty()
{
    if(top==0)
        return true;
    else
        return false;
}

char Top()
{
    return Stack[top];
}

void display(char Stack[],int top)
{
    cout<<"----THE STACK IS----\n";
    cout<<Stack[top]<<"<--\n";
    for(int i=top-1;i>0;i--)
        cout<<Stack[i]<<"\n";
}
