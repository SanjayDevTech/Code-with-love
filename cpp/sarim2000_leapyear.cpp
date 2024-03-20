// C++ program to check if a given 
// year is leap year or not 
#include <bits/stdc++.h>
using namespace std; 

bool checkYear(int year) 
{ 
	// If a year is multiple of 400, 
	// then it is a leap year 
	if (year % 400 == 0) 
		return true; 

	// Else If a year is muliplt of 100, 
	// then it is not a leap year 
	if (year % 100 == 0) 
		return false; 

	// Else If a year is muliplt of 4, 
	// then it is a leap year 
	if (year % 4 == 0) 
		return true; 
	return false; 
} 

// Driver code 
int main() 
{ 
	int year; cin >> year ;

	if  (checkYear(year)  cout << "It's a leap year.";
  else cout << "It's not.";
	return 0; 
} 
