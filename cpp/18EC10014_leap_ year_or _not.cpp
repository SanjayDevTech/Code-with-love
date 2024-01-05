bool isLeapYear(int n)
{
    if(n%400==0)
    {
     return 1;
    }
    else if(n%100==0)
    {
     return 0;
    }
    else if(n%4==0)
    {
     return 1;
    }
}    

int main()
{
int year;
cout<<"Enter the year ";
cin>>year;
   if(isLeapYear(year))
   {
  cout<<"The year "<<year<<" is a leap year";
   }
   else
   {
   cout<<"The year "<<year<<" is not a leap year";
   }
}  
