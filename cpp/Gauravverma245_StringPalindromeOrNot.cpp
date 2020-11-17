#include<bits/stdc++.h>
using namespace std;


// Program to check whether a string is palindrome or not.

int main() {

    string s;
    cin>>s;   // taking input string.

    string ans = s;   // making a copy of input string.
    reverse(s.begin(), s.end());   // reversing our original string.

    if(ans==s)  //If copied string and reversed string are same then original string is palindrome
      cout<<"Palindrome"<<endl;
    else                        // If not same the print Not Palindrome.
      cout<<"Not Palindrome"<<endl;
    

    return 0;
}
