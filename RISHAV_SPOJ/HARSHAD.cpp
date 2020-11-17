#include<stdio.h>

char num[1000100],dev[1000100];  int res[1000005]={0};

int main()
{
 int i,j,k,n,temp,sum;

 i = -1;
 while(++i < 1000100)
  num[i] = dev[i] = '1';

 for(i = 3; i <= 1000; i += 2 )
  if(num[i] == '1')
   for(j=i*i, k = i<<1; j<=1000000; j += k)
    num[j] = '0';

 dev[0] = '0'; res[0] = 0; num[1] = '0';

 for(i=1;     i<=1000000; i++)
 {
  if( (i&1)  && dev[i] == '1' && num[i] == '1')
  {
   res[i] = res[i-1] + 1;
  }

  else
  {
   res[i] = res[i-1];
  }

  temp = sum = i;

  while(temp)
  {
   sum += ( temp % 10 );
   temp /= 10;
  }

  dev[sum] = '0';

 }

 scanf("%i",&n);

 while(n--)
 {
  scanf("%i%i",&i,&j);

  if( (i&1)  && dev[i] == '1' && num[i] == '1')
   printf("%i\n",res[j] - res[i] + 1);
  else
   printf("%i\n",res[j] - res[i]);
 }

 return 0;
}
