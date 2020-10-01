#include <bits/stdc++.h>
using namespace std;
 
int check_year(int year)
{
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
      return 1;
    return 0;
}
 
int main()
{
    int year,res;
    cout<<"Enter the year"<<endl;
    cin>>year;
    
    res=check_year(year);
    if(res==0)
    cout<<year<<" is not a leap year"<<endl;
    else
    cout<<year<<" is a leap year"<<endl;
    
    return 0;
}
