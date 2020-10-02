#include<iostream>
using namespace std;
int main() {
   int a, b,i;
   cout<<"Enter a : ";
   cin>>a;
   cout<<"Enter b : ";
   cin>>b;
   for(i=(a>b?a:b);i<=(a*b);i=i+(a>b?a:b)){
       if(i%a==0 && i%b==0){
           break;
       }
   } 
   cout<<"LCM is "<<i<<endl;
}