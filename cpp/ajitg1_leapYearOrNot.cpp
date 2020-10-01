#include <bits/stdc++.h>
using namespace std;

bool checkYear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) ||
             (year % 400 == 0));
}

int main()
{
    int year = 2020;
    checkYear(year)? cout << "Leap Year":
                     cout << "Not a Leap Year";
    return 0;
}
