#include <iostream>

using namespace std;

/* 
This program accepts 3 numbers and swaps the
first no -> third
second no -> first
third no -> second

without using any external variables except the input variables
*/

int main()
{
    int n1, n2, n3;

    cout << "Enter First Number : ";
    cin >> n1;

    cout << "Enter Second Number : ";
    cin >> n2;

    cout << "Enter Third Number : ";
    cin >> n3;

    n1 = n1 ^ n2 ^ n3;
    n2 = n1 ^ n2 ^ n3;
    n3 = n1 ^ n2 ^ n3;
    n1 = n1 ^ n2 ^ n3;

    cout << "The three swapped numbers are : " << endl
         << "First Number (swapped): " << n1 << endl
         << "Second Number (swapped): " << n2 << endl
         << "Third Number (swapped): " << n3 << endl;

    return 0;
}