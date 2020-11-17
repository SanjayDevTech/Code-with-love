#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
int isprime(int n);
int main()
{
	int n;
	cin>>n;
	if(n==1)
	    cout<<"1 is neither prime nor composite.";
	else
	{
		if(isprime(n))
	    		cout<<"given number is prime number.";
		else
	   		cout<<"given number is not a prime number.";
	}
	return 0;
}  

 //function for prime_check
 int isprime(int n)
 {
 	int i;
 	for(i=2;i<=n/2;i++)
 	{
 		if(n%i==0)
 		    return 0;
	}
   return 1;
  }
  
   /*sample input-output
   23
   given number is a prime number. */
