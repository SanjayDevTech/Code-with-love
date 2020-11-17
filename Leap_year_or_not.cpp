#include <iostream>

using namespace std;

int main()
{
    // the yaer tou want to check
   int year;
   cin>>year;
   // century year should be divisible by 400 and not 100
   if((year%4==0 &&  year%100!=0) || year%400==0)
    cout<<"It is a leap year";
   else
    cout<<"It is not a leap year";
}
