#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int n = str.size();
    for (int i = 0; i < n/2; ++i) {               // loop through half of the string
        if(str[i] != str[n-i-1]) {				  // check if characters at start and end are not same
            cout << "Not a palindrome";			
            return 0;							  // return the function as it's not a palindrome
        }
    }
    cout << "It is a palindrome";
    return 0;
}
