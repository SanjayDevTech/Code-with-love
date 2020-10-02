// Question: To check the year is a leap year or not.

#include<iostream>
using namespace std;

void leapYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0))
    {
        cout<<"Yes it's a leap year"<<endl;
    }
    else
    {
        cout<<"No it's not a leap year"<<endl;
    }
    
}
int main()
{
    int year;
    cin>>year;
    {
        leapYear(year);
    }
    return 0;
}