#include <iostream>
#include <string>

using namespace std;

// Using Recursion
// Function Call
int palindrome (string &s){
    static auto itb = s.begin(), ite = s.end() - 1;
    if(itb > ite){
        return 0;
    }
    else if(*itb != *ite){
        return 1;
    }
    itb +=1;
    ite -=1;
    return palindrome(s);

}

int main(){
    string s;

    cout << "Enter string : ";
    getline(cin, s);


    int flag = palindrome(s);
    if(flag == 1){
        cout << "Not Palindrome ";
    }
    else{
        cout << "Palindrome ";
    }

    return 0;
    
}