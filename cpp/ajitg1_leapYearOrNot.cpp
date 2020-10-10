#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool checkYear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) ||
             (year % 400 == 0));
}

int main()
{
    int year = -1;
	cout << "Enter a year (A.D.) to see if it is or was a leap year: ";
	cin >> year;
	cout << endl;
	
    checkYear(year)? cout << year << " was a Leap Year." << endl:
                     cout << "Not a Leap Year" << endl;
    return 0;
}
