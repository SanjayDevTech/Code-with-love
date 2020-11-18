//This code checks whether an entered year is leap year or not

#include<iostream>
#include<string.h>
using namespace std;

int check_leap(int x)
{
    //Here we check if the year is divisible by 4 and not a century year or the year is divisible by 400
	if(((x % 4 ==0)&&(x % 100 != 0)) || (x % 400 ==0))
		return 1;
	else 
		return 0;
}

int main()
{
	int year,res;
	cout<<"Enter any year in yyyy format: ";
	cin>>year;
	res= check_leap(year);
	if(res)
		cout<<year<<" is a leap year";
	else
		cout<<year<<" is not a leap year";
	return 0;
}