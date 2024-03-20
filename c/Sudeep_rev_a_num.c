//program to find reverse of a number

#include <stdio.h>

int main()
{
   int num, rev = 0;

   printf("Enter a number to reverse\n");
   scanf("%d", &num);

   while (num != 0)
   {
      rev = rev * 10;
      rev = rev + num%10;
      num      = num/10;
   }

   printf("Reverse of entered number is = %d\n", rev);

   return 0;
}
