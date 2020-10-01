// Created by js0805
#include<iostream>
using namespace std;
void solve() {
	int year;
	cin >> year;
	//We check for two conditions which are as folllows
	//1.If the year is leap it must return 0 reminder when divided by 4 and it should
	//not return 0 when divided by 100.
	//2. If it is only divisible by 400 then this condition is itself sufficent to call a year leap.

	if ((year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)) {
		cout << "It is a leap year." << "\n";
	}
	// Else in all other cases it will not be a leap year
	else {
		cout << "It is not a leap year" << "\n";
	}
}
int main()
{
	//to check for more than one years in one go.
	//input the number of test cases which you wish to test.
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}