/*
 * Author : Rohit Shakya
 * Date   : July-2020
 * Compiler : g++ 4.9.2
 * Flags    : -std=c++14
 * Time complexity : 
 * Title : 
 */
#include<bits/stdc++.h>
using namespace std;
bool leapYear(int year)
{
	if(year%400==0) return true;
	else if(year%100==0) return false;
	else if(year%4==0) return true;
	return false;
}
int main()
{
	int year;
	cout<<"enter the year\n";
	cin>>year;
	cout<<leapYear(year); 
}
