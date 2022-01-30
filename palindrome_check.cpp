#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int length=s.length();
    // length is the of string

    int i;

    for(i=0;i<length/2;i++)
    {
        if(s[i]!=s[length-1-i])
        {
            cout<<"It is not a palindrome";
            break;
        }
    }
    if(i==length/2)
        cout<<"It is a palindrome";

}
