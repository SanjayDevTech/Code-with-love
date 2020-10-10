// Swapping two numbers using third variable

#include<stdio.h>
int main ()

{
	int a,b,x;
	printf("enter the value of a and b=");
	scanf("%d%d",&a,&b);
	x=a;
	a=b;
	b=x;
	printf("values after swapping are a=%d\nand b=%d",a,b);
	return 0;
	
}
