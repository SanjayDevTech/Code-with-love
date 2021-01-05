//Program for finding that the given year is leap year or not

#include <stdio.h>
int main() {
   int year;
   printf("Enter a year: ");
   scanf("%d", &year);
   //checks only if the year is more than 0
   if(year>=0){
      // leap year if perfectly visible by 400
      if (year % 400 == 0) {
         printf("%d is a leap year.", year);
      }
      // not a leap year if visible by 100
      // but not divisible by 400
      else if (year % 100 == 0) {
         printf("%d is not a leap year.", year);
      }
      // leap year if not divisible by 100
      // but divisible by 4
      else if (year % 4 == 0) {
         printf("%d is a leap year.", year);
      }
      // all other years are not leap year
      else {
         printf("%d is not a leap year.", year);
      }
   }
   else{
      printf("Invalid year.");
   }

   return 0;
}
