//C++ Program to check Whether a year(Given as an input) is leap year or not
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int year;

	cout << "Enter the year you want to check: ";
	cin >> year;

	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		cout << year  << " is a leap year" << endl;
	else
		cout << year << " is not a leap year" << endl;
}

/*
input :-
2020
Output :-
2020 is a leap year
*/