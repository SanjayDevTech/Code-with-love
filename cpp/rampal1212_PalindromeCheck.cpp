#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int l = 0, r = str.length()-1;
    while (l <= r) {
        if(str[l] != str[r]) {
            cout << "It is not a palindrome";
            return 0;
        }
        l++;
        r--;
    }
    cout << "It is a palindrome";
    return 0;
}
