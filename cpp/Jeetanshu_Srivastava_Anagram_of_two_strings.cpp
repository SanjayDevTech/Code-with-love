#include<bits/stdc++.h>
int main()
{
    int len1,len2;
    string str1,str2;
    cin>>str1;
    cin>>str2;
    len1=str1.size();
    len2=str2.size();
    sort(str1,str1+len1);
    sort(str2,str2+len2);
    if(str1==str2)
    cout<<"Anaagram";
    else
    cout<<"Not Anagram";
    return 0;
}