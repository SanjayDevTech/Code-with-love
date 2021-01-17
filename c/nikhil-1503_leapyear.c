#include <stdio.h>
 
int check_year(int year)
{
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
      return 1;
    return 0;
}
 
int main(){
    int year,res;
    printf("Enter the year\n");
    scanf("%d",&year);
    
    res=check_year(year);
    if(res==0)
    printf("\n%d is not a leap year",year);
    else
    printf("\n%d is a leap year",year);
    
    return 0;
}
