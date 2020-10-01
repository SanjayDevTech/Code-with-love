// Binary Exponentiation algorithm
// Iterative solution

#include <iostream>
#include <cmath>

using namespace std;

int64_t binaryExponentiation(int64_t a, int64_t n){
    // Initializing result with 1
    int64_t res = 1;
    
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
    int64_t a, n;
    cout << endl << "Enter a & n : ";
    cin >> a >> n;

    int64_t res = binaryExponentiation(a, n);
    cout << endl << "Result : " << res;

    return 0;
}
