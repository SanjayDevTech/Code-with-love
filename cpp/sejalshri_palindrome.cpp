#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void myfunction();
int main() {
    int n,count=0,rev=0,i,t;
    
    //take number from user
    cin>>n;
    t=n;
    
    //to count digits of a number
    count=(int)log10(n);
    
    //to find reverse of a number
   while(t!=0)
   {
       i=t%10;
       rev=rev+(i* pow(10,count));
       t=t/10;
       count--;
   }
   
   //check whether it is palindrome or not
   if(rev==n)
   {
   cout<<"given number is a palindrome number";
   }
   else
   cout<<"given number is not a palindrome number";
}

/* sample input-output
454
given number is palindrome number*/
