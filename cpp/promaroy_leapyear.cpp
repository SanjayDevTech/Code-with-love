
// a year is leap if either it is divisible by 4 and not divisible by 100 OR it is divisible by 400

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int year;
  cout<<"enter the year"<<endl;
  cin>>year;
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
      cout<<"This is a leap year"<<endl;
  else
      cout<<"This is not a leap year"<<endl;
}
