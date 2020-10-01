#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    bool f = 0; //tells whether prime or not
    for (int i = 2; i*i <= num; ++i) {
        if (num % i == 0)
            f = 1;
    }
    if(f || num <= 1) {
        cout << num <<" is not a prime number";
    }
    else {
        cout << num <<" is a prime number";
    }
    return 0;
}
