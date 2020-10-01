#include <iostream>
using namespace std;

void number_pyramid(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

void half_pyramid(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << '*' << " ";
        }
        cout << "\n";
    }
}
void inverted_half_pyramid(int rows) {
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i ; j++) {
            cout << '*' << " ";
        }
        cout << "\n";
    }
}

void full_pyramid(int n) {
// number of spaces 
    int k = 2 * n - 2; 
  
    // Outer loop to handle number of rows 
    // n in this case 
    for (int i = 0; i < n; i++) { 
  
        // Inner loop to handle number spaces 
        // values changing acc. to requirement 
        for (int j = 0; j < k; j++) 
            cout << " "; 
  
        // Decrementing k after each loop 
        k = k - 1; 
  
        // Inner loop to handle number of columns 
        // values changing acc. to outer loop 
        for (int j = 0; j <= i; j++) { 
            // Printing stars 
            cout << "* "; 
        } 
  
        // Ending line after each row 
        cout << endl; 
    } 
}

int main(int argc, char const *argv[])
{
    // you can call any of the above functions
    half_pyramid(7);
    return 0;
}