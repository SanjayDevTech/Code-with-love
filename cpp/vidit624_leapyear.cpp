// created by vidit624
#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	cout << "+----------------------------------------------------------+" << endl;
	cout << "Welcome to check whether the year is Leap year or not" << endl;
	// to store which year we have to check
	int year;
	// taking input from the user
	cout << "Enter Year: ";
	cin >> year;
	//We check for two conditions which are as folllows
	//1.If the year is leap the reminder should be 0 when divided by 4 and it should not 0 when divided by 100
	//2.If it is only divisible by 400 then this condition is itself sufficent to call a year leap.
	if((year%4 == 0 && year %100 !=0) || (year %400 == 0))
	{
		cout << year << " is a leap year" << endl;
	}
	else
		cout << year << " is not a leap year" << endl;
	return 0;
}