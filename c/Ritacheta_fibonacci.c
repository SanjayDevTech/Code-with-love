#include<stdio.h>
int main()
{
    int n, i, t1=0, t2=1, sum=0;
    printf("enter a number till which you want to see the fibonacci series:");
    scanf("%d", &n);
    printf("fibonacci series: ")
    for(i=2;i<=n;i++)
    {
     	sum= (t1+t2);
     	t1=t2;
     	t2=sum;
        printf("%d,",sum);}
    return 0;
}
