#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    cout<<"Enter c: ";
    cin>>c;
    int result=0;
    if(a>b){
        result=a>c?a:result=c;
    }
    else{
        result=b>c?b:c;
    }
    cout<<"Greatest number is "<<result<<endl;
    return 0;
}