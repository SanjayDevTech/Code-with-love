#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int n = str.size();
    for (int i = 0; i < n/2; ++i) {
        if(str[i] != str[n-i-1]) {
            cout << "Not a palindrome";
            return 0;
        }
    }
    cout << "It is a palindrome";
    return 0;
}
