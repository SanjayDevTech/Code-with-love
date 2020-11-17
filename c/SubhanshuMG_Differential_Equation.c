#include <stdio.h>
#include <conio.h>
#include <math.h>

float poly(float a[], int, float);
float deriv(float a[], int, float);

int main()
{
	float x, a[10], y1, dy1;
	int deg, i;

	printf("Enter the degree of polynomial equation: ");
	scanf("%d", &deg);

	printf("Ehter the value of x for which the equation is to be evaluated: ");
	scanf("%f", &x);

	for(i=0;i<=deg;i++)
	{
		printf("Enter the coefficient of x to the power %d: ",i);
		scanf("%f",&a[i]);
	}

	y1 = poly(a, deg, x);
	dy1 = deriv(a, deg, x);

	printf("The value of polynomial equation for the value of x = %.2f is: %.2f",x,y1);
	printf("\nThe value of the derivative of the polynomial equation at x = %.2f is: %.2f",x,dy1);

	return 0;
}

/* function for finding the value of polynomial at some value of x */

float poly(float a[], int deg, float x)
{
	float p;
	int i;

	p = a[deg];

	for(i=deg;i>=1;i--)
	{
		p = (a[i-1] + x*p);
	}
	
	return p;
}

/* function for finding the derivative at some value of x */
float deriv(float a[], int deg, float x)
{
	float d[10], pd = 0, ps;
	int i;

	for(i=0;i<=deg;i++)
	{
		ps = pow(x, deg-(i+1));
		d[i] = (deg-i)*a[deg-i]*ps;
		pd = pd + d[i];
	}

	return pd;
}
