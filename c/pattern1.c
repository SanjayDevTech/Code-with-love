/*
* * * * * * * * * * * * * * * * *
  * * * * * * *   * * * * * * *
    * * * * *       * * * * *
      * * *           * * *
        * * * * * * * * *
          * * * * * * *
            * * * * *
              * * *
                *
*/

#include<stdio.h>
int main() 
{
 char prnt = '*';
 int i, j, k, s, sp, n = 0, m = -1;
 for (i = 9; i >= 3; (i = i - 2)) {
  	for (s = n; s >= 1; s--)
	   {
   		printf("  ");
  		}
  		
   for (j = 1; j <= i; j++)
   {
		printf("%2c", prnt);
	}
	for (sp = m; sp >= 1; sp--)
	 {
   		printf("  ");
  	 }
for (k = 1; k <= i; k++) 
{
 if (i == 9 && k == 1)
 {
continue;
}
printf("%2c", prnt);
}
n++;
m = m + 2;
printf("\n");
}
n = 4;
for (i = 9; i >= 1; (i = i - 2)) {
  for (s = k; s >= 1; s--) {
   printf("  ");
  }
  for (j = 1; j <= i; j++) {
   printf("%2c", prnt);
  }
  k++;
  printf("\n");
 }

 return 0;
}
