#include <iostream>
using namespace std;
void leapornot(int year)
{
       if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
      cout << year << " is a leap year." << endl;
   else
      cout << year << " is not a leap year." << endl;

}

int main()
{
   int year;

   cout << "Enter a year you want to check: ";
   cin >> year;
   leapornot(year);
  return 0;
 }
