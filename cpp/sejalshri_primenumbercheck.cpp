#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
int isprime(int n);
int main()
{
	int n;
	cin>>n;
	if(n==1)
	{
	    cout<<"1 is neither prime nor composite.";
	}
	else
	{
	if(isprime(n)==1)
	{
	    cout<<"given number is prime number.";
	}
	if(isprime(n)==0)
	{
	    cout<<"given number is not a prime number.";
	}
	}
	return 0;
}  

 //function for prime_check
 int isprime(int n)
 {
 	int i,count=0;
 	for(i=1;i<=n/2;i++)
 	{
 		if(n%i==0)
 		 {
 			count++;
		 }
	 }
   
   //if a number is only divisible by 1 in the above loop.
	 if(count==1)
	 {
	 	return 1;
	 }
   //if a number is divisible by more than one number in above loop
	 else
	 {
	 	return 0;
	 }
  }
  
   /*sample input-output
   23
   given number is a prime number. */
