// Binary Exponentiation algorithm
// Iterative solution

#include <iostream>
#include <cmath>

using namespace std;

long long bipower(long long a, long long n){
    // Initializing result with 1
    long long res = 1;
    
    // Looping to calculate result
    while(n > 0){
        // Checking if bit is high or not
        if(n & 1){
            // Updating res only when bit is high
            res = res * a;
        }

        // Updating a
        a = a * a;
        // Right shift 
        n = n >> 1;
    }
    return res;
}
 
int main(){
    long long a, n;
    cout << endl << "Enter a & n : ";
    cin >> a >> n;

    long long res = bipower(a, n);
    cout << endl << "Result : " << res;

    return 0;
}
