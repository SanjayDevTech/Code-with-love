#include<iostream>
using namespace std;
int main()
{
  int year;
  cin >>year;
  if(y%400 == 0)
  cout<<"Leap year \n";
  else if(year%100 !=0 && year%4 == 0)
  cout<<"Leap year \n";
  else
  cout<<"Not leap year \n";
  return 0;
}
