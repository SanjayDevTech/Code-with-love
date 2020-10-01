#include<bits/stdc++.h>
using namespace std;
void sub(string input,string output){
    if(input.length()==0){
        cout<<output;
        return;
    }
    sub(input.substr(1),output);
    cout<<", ";
    sub(input.substr(1),output+input[0]);
}
int main(){
    string input;
    cin>>input;
    string output="";
    cout<<"[";
    sub(input,output);
    cout<<"]";
}
